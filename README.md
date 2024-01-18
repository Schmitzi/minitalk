<p align="center">
    <img src="img/minitalkm.png"/>
</p>

<h1 align="center">
   minitalk
</h1>

<p align="center">
    <img src="https://img.shields.io/badge/language-%20C-blue" />
    <img src="https://img.shields.io/badge/110%2F100-green" />
</p>

## Client Program

### Overview

The client program transmits a message to a specified process ID (PID) using a custom communication protocol based on signals. It converts each character in the message into a sequence of signals and sends them to the server process.

### Functions

#### 1. `send_signal(int pid, unsigned char character)`

- **Parameters:**
  - `pid`: The process ID of the server.
  - `character`: The character to be transmitted.

- **Description:**
  - Converts the given character into a sequence of signals and sends them to the server process specified by the PID.

#### 2. `main(int argc, char **argv)`

- **Parameters:**
  - `argc`: The number of command-line arguments.
  - `argv`: An array of strings representing command-line arguments.

- **Description:**
  - Main function of the client program.
  - Validates the command-line arguments.
  - Iterates through each character in the message, converting and transmitting them using `send_signal`.
  - Prints a message indicating the completion of message transmission.

### Usage

To use the client program, execute it from the command line with the following syntax:

```bash
./client "PID" "message"
```

- `"PID"`: The process ID of the server.
- `"message"`: The message to be transmitted.

### Example

```bash
./client 12345 "Hello, Server!"
```

## Server Program

### Overview

The server program listens for signals sent by the client, decodes them, and reconstructs the original message. It displays the received message on the console.

### Functions

#### 1. `handle_signal(int signal)`

- **Parameters:**
  - `signal`: The received signal (SIGUSR1 or SIGUSR2).

- **Description:**
  - Called when a signal is received.
  - Decodes the signal to reconstruct the original message character by character.
  - Prints the reconstructed character when a complete character is received.

#### 2. `main(void)`

- **Description:**
  - Main function of the server program.
  - Displays the server's process ID.
  - Sets up signal handlers for SIGUSR1 and SIGUSR2.
  - Enters an infinite loop using `pause()` to wait for signals.

### Usage

Run the server program from the command line:

```bash
./server
```

## Protocol Details

- The client sends signals representing each bit of a character, with SIGUSR1 indicating a '1' bit and SIGUSR2 indicating a '0' bit.
- The server decodes the received signals to reconstruct the original message.
