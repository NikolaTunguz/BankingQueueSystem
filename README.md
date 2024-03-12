## Banking Queue System
This program implements the event-driven simulation of a bank. A queue of arrival events will represent the line of customers in the bank. This program maintains arrival and departure events in a circular array based priority queue, sorted by the time of the event. 

The program counts customers and keeps track of their cumulative waiting time. These statistics are used to compute the average waiting time and a trace of the events executed with a summary of the computed statistics are displayed.

## HOW TO RUN
In terminal, run the "make" command. This will create an executable called "Bank". To run the program, run this executable along
with the transaction data in the form of a text file, for example "./Bank transactionData.txt".

The "transactionData.txt" is a text file of arrival and transaction times. Each line of the file contains the arrival time and required transaction time for a customer. The arrival times are ordered by increasing time.
The results of all transactions will be output into the terminal.