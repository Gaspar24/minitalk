Client-Server Communication Program
Overview
This project implements a communication system between a client and a server using UNIX signals. The server receives a string sent by the client, and upon successful reception, the server displays the string. The project also adheres to strict requirements regarding error handling, memory management, and performance.

Features
Client:

Sends a string to the server using UNIX signals.
Passes the server's PID and the string as command-line arguments.
Server:

Receives the string sent by the client and displays it.
Handles multiple clients sequentially without needing to restart.
Prints its PID upon launch for the client to use.
Communication:

Uses only SIGUSR1 and SIGUSR2 for transmitting data.
Ensures efficient and prompt display of strings.
Requirements
The project uses the following functions:
Signal handling: signal, sigaction, sigemptyset, sigaddset, kill
Process management: getpid, pause, sleep, usleep
Memory management: malloc, free
Output: write, ft_printf (or an equivalent custom implementation)
Exit: exit
No memory leaks or unexpected crashes (e.g., segmentation faults, bus errors).
One global variable allowed per program, with a valid justification for its use.
Adheres to rigorous error handling.
Compilation
Use the provided Makefile to compile the project:

bash
make
This will produce two executable files:

client
server
Usage
Start the server:

bash
./server
The server will print its PID to the console. Keep this PID for the next step.

Run the client:

bash
./client <server_PID> "<message>"
Replace <server_PID> with the PID displayed by the server and <message> with the string you want to send.

Example
Start the server:

bash
$ ./server
Server PID: 12345
Send a message from the client:

bash
$ ./client 12345 "Hello, Server!"
Server output:

bash
Received: Hello, Server!
Learning Outcomes
Signal Handling:

Learned how to use UNIX signals (SIGUSR1 and SIGUSR2) for communication.
Understood the role of sigaction in setting up custom signal handlers.
Process Synchronization:

Implemented inter-process communication while ensuring efficient data transfer and reception.
Error Handling:

Devised strategies to handle invalid input, signal interruptions, and unexpected process behavior.
Memory Management:

Managed dynamically allocated memory carefully to avoid leaks or corruption.
Performance Optimization:

Minimized latency during string transmission and ensured prompt display of messages.
Challenges and Solutions
Signal Transmission Efficiency:

Challenge: Sending data bit by bit using signals introduced delays.
Solution: Optimized signal sending loops to maintain acceptable transmission speeds.
Handling Signal Queues:

Challenge: UNIX signals do not queue, leading to potential data loss.
Solution: Used acknowledgments and synchronization mechanisms to ensure data integrity.
Unicode Character Support:

Challenge: Handling multi-byte characters for Unicode compatibility.
Solution: Extended the bit-level transmission logic to handle Unicode encoding.
Error Recovery:

Challenge: Managing unexpected errors like invalid PID or interrupted signals.
Solution: Implemented comprehensive error checks and graceful exits.
Bonus Features
The following features were implemented as part of the bonus section:

Acknowledgments:
The server sends a signal back to the client after successfully receiving the message.
Unicode Support:
Enhanced the program to handle Unicode characters seamlessly.
Project Structure
bash
.
├── client.c        # Client-side implementation
├── server.c        # Server-side implementation
├── Makefile        # Build system
├── libft/          # (Optional) Libft library for additional utility functions
├── README.md       # Project documentation
Error Handling
The program handles errors gracefully, including:

Invalid arguments (e.g., missing PID or message in the client).
Invalid PIDs or non-existent processes.
Signal interruptions or unexpected process termination.
Error messages are displayed to standard error:
Error: Invalid arguments
Conclusion
This project provided a comprehensive learning experience in inter-process communication, signal handling, and efficient 
data transfer using UNIX signals. By tackling challenges such as signal queuing and Unicode support, I deepened my understanding of 
low-level programming concepts. The implementation is robust, efficient, and adheres to all project specification
