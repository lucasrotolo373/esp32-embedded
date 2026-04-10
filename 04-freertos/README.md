# ESP32 FreeRTOS Multitasking with Mutex

Fourth project in my ESP32 embedded systems portfolio.

## What it does
Runs three concurrent tasks using FreeRTOS:
- **Task 1**: Blinks onboard LED every 500ms
- **Task 2**: Reads LM35 temperature sensor, averages 10 readings every 5s
- **Task 3**: Prints a heartbeat counter every 1 second

## Key concepts demonstrated

### Concurrency vs Parallelism
The ESP32 has two cores. FreeRTOS can achieve true parallelism by pinning
tasks to different cores, or concurrency by time-slicing tasks on the same
core. Tasks with equal priority use round-robin scheduling with 1ms ticks.

### vTaskDelay vs delay()
`delay()` blocks the entire core. `vTaskDelay()` suspends only the current
task and yields the CPU to the scheduler, allowing other tasks to run.

### Race condition
Without synchronization, multiple tasks printing to Serial simultaneously
produced garbled output like `HEARTBEAT: 30LED: OFF`. This is a classic
race condition caused by interleaved instructions between tasks.

### Mutex solution
A FreeRTOS mutex (`SemaphoreHandle_t`) wraps all Serial access.
`xSemaphoreTake()` blocks until the mutex is free, then locks it.
`xSemaphoreGive()` releases it. Internally implemented using atomic
test&set hardware instructions to prevent interleaving.

## Hardware
- ESP32 NodeMCU 38-pin (CP2102)
- LM35DZ temperature sensor on GPIO34

## How to flash
1. Install PlatformIO in VS Code
2. Clone this repo
3. Run `pio run --target upload` inside the `04-freertos` folder

## Serial output
Open monitor at 115200 baud.
