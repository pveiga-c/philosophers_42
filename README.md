# Philosophers

## Description

The **philosophers** project is an introduction to multithreading and process synchronization in C. The goal is to simulate the dining philosophers problem using threads and mutexes while preventing race conditions and deadlocks.

## Program Usage

The program should be executed as follows:

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Arguments:
- `number_of_philosophers`: Number of philosophers and forks.
- `time_to_die`: Maximum time (in milliseconds) a philosopher can go without eating before dying.
- `time_to_eat`: Time (in milliseconds) a philosopher spends eating.
- `time_to_sleep`: Time (in milliseconds) a philosopher spends sleeping.
- `[number_of_times_each_philosopher_must_eat]` (optional): If provided, the simulation stops once all philosophers have eaten at least this many times.

### Example:
```sh
./philo 5 800 200 200
```
This will start a simulation with 5 philosophers, each having 800ms to eat before dying, taking 200ms to eat, and 200ms to sleep.

## Program Rules

- Each philosopher must be represented as a separate thread.
- A philosopher must pick up both forks (mutex-protected) before eating.
- Philosophers alternate between eating, sleeping, and thinking.
- The program must print timestamped logs of philosopher actions:
  - `X has taken a fork`
  - `X is eating`
  - `X is sleeping`
  - `X is thinking`
  - `X died`
- A philosopher dies if they do not eat within `time_to_die` milliseconds.
- The simulation stops if any philosopher dies or if all philosophers eat the required number of times.

## Project Requirements

- The program must be named `philo`.
- The following functions are allowed:
  - `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`.
- The code must not have race conditions or deadlocks.
- Global variables are forbidden.

## Author

Pedro Cristóvão Veiga Correia

