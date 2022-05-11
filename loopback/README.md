# Loopback Application

This application loops back input data from ADC to DAC. It is designed for TI `D.Module.ADDA8M12` and `D.Module2.C6747` encoder boards. Additionally, it can be built for typical x86 hardware in _simulation mode_.

## Required Tools

To build the application in simulation mode you'll need at least the following tools:

* doxygen (optional, only for generating documentation)
* gcc - GNU Compiler Collection
* make - Build tool able to read `Makefile`

On Linux these are easily installed using your distributions package manager.

### Debian/Ubuntu

```sh
sudo apt update && sudo apt install build-essential
```

### Arch Linux

```sh
sudo pacman -Sy base-devel
```

### RedHat/CentOS/Fedora

```sh
sudo dnf groupinstall "Development Tools" "Development Libraries"
```

## Building

The provided `Makefile` is designed for Linux/UNIX systems (but also Windows using [WSL](https://docs.microsoft.com/en-us/windows/wsl/), [MinGW](https://www.mingw-w64.org/) or [Cygwin](https://www.cygwin.com/)). By default, it uses `gcc` (GNU Compiler Collection). This behavior can be changed using the `CC` environment variable.

Build targets:

```sh
make                    # build application binary using gcc
make all                # ^ same as above
make loopback_starter   # ^ same as above

make doxygen            # generate doxygen documentation

make clean              # delete generated build files and binaries
```

**Building the application for the embedded target is not supported.**

## Running in Simulation Mode

After building, you'll find the application binary in `./bin/loopback_starter`. Building it in simulation mode requires an input file in the current working directory. Upon startup `loopback_starter` will search the current directory for a `y_cpfsk_sig.mat`. This is provided in the `data/` directory. The application can be built and started like so:

```sh
make # build application
cd data # change directory into the data directory
../bin/loopback_starter # run loopback application
```

Samples are taken from `y_cpfsk_sig.mat` and written to a new file called `ADDA8M12_DAC_data.mat`.
