# ESP32 Stack Memory Analysis with FreeRTOS

Eighth project in my ESP32 embedded systems portfolio.

## What it does
Deliberately exhausts the stack of a FreeRTOS task using recursion,
monitoring memory consumption in real time until the system crashes.
Demonstrates stack behavior, memory layout, and FreeRTOS protection mechanisms.

## Key concepts demonstrated

### Stack grows downward
Each recursive call allocates a new frame below the previous one.
Observed in practice: buffer addresses decrease by ~96 bytes per level
(50 bytes buffer + function frame overhead).

### Stack Watermark
`uxTaskGetStackHighWaterMark(NULL)` returns the minimum free stack bytes
since the task started. Used to tune stack size — if watermark is close
to zero, the task is at risk of overflow.

### Stack Canary
FreeRTOS places a special "canary" value at the bottom of each task stack.
If a write overwrites the canary, FreeRTOS detects the overflow and triggers
a controlled reset with:
Stack canary watchpoint triggered (Tarea:1)
This prevents silent memory corruption — instead of undefined behavior,
the system fails loudly and predictably.

### Compiler optimizations change program semantics
In the first version without `&buffer`, the compiler applied
**tail call optimization** — since `consumirStack` called itself
as the last instruction, the compiler reused the same stack frame
instead of creating a new one. The watermark never decreased.

When `&buffer` was added (taking the address of the local variable),
the compiler was forced to materialize the buffer in real memory,
breaking the optimization. The stack started growing correctly.

**Lesson**: compiler optimizations can silently change program behavior.
In embedded systems this is critical — timing, memory layout, and
debugging code can all be affected. Use `volatile` keyword or
`-O0` flag to disable optimizations when needed.

### Memory layout observed
Level 0:  0x3FFB324A  Watermark: 3228
Level 10: 0x3FFB2E2A  Watermark: 2364
Level 20: 0x3FFB2A0A  Watermark: 1212  (96 bytes per level)
Level 34: CRASH - Stack canary triggered

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)
- No external components needed

## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Run `pio run --target upload` inside the `08-memory` folder

## Serial output
Open monitor at 115200 baud.
Watch buffer addresses decrease and watermark approach zero until crash.
