## Simba Bus Reservation System

## Overview
Simba Bus Reservation System is a simple console-based application that allows users to check bus availability, book tickets, cancel bookings, and view bus status. It provides a basic reservation system for a bus company.

## Features
- View available buses
- Book tickets for a specific bus
- Cancel booked tickets
- Check the status of a bus, including seat availability

## How to Use
1. Run the program.
2. Log in using the provided username and password.
3. Choose from the available options:
   - **Bus Available:** View available buses.
   - **Book Ticket:** Reserve seats on a bus.
   - **Cancel Booking:** Cancel a previously booked ticket.
   - **Bus Status:** Check the status and availability of seats on a bus.
   - **Exit:** Quit the application.

## File Structure
- **bus.c:** The main C file containing the source code.
- **busX.txt:** Files storing booking details for each bus, where X is the bus number.
- **bsX.txt:** Files storing the available seats for each bus, where X is the bus number.

## How to Compile
Compile the program using a C compiler (e.g., GCC):
```bash
gcc bus.c -o bus_reservation
