# ✈️ Flight Booking System - C++ OOCP Project

A simple console-based **Flight Booking System** developed in C++ for a college OOCP project.

## Main Features

- Passenger registration and login
- Admin login
- View and search flights
- Seat selection
- Flight booking
- Extra baggage calculation
- UPI / Card / Cash payment simulation
- Ticket and PNR generation
- Booking history
- Booking cancellation
- Admin can add/remove flights
- Basic file handling using `.dat` files

## OOP Concepts Demonstrated

- Class and Object
- Encapsulation
- Abstraction
- Inheritance
- Runtime Polymorphism
- Function Overriding
- Constructors / Destructors
- Composition
- Arrays
- File Handling

## Project Structure

```text
FlightBookingSystem/
│
├── main.cpp
│
├── classes/
│   ├── User.h
│   ├── Passenger.h
│   ├── Admin.h
│   ├── Airport.h
│   ├── Flight.h
│   ├── Seat.h
│   ├── Booking.h
│   ├── Ticket.h
│   ├── Payment.h
│   └── Baggage.h
│
├── implementations/
│   ├── User.cpp
│   ├── Passenger.cpp
│   ├── Admin.cpp
│   ├── Airport.cpp
│   ├── Seat.cpp
│   ├── Flight.cpp
│   ├── Baggage.cpp
│   ├── Ticket.cpp
│   ├── Payment.cpp
│   └── Booking.cpp
│
├── data/
│   ├── flights.dat
│   ├── passengers.dat
│   └── bookings.dat
│
└── README.md
```

## Compile

From inside the project folder:

```bash
g++ -std=c++17 main.cpp implementations/User.cpp implementations/Passenger.cpp implementations/Admin.cpp implementations/Airport.cpp implementations/Seat.cpp implementations/Flight.cpp implementations/Baggage.cpp implementations/Ticket.cpp implementations/Payment.cpp implementations/Booking.cpp -o FlightBookingSystem
```

### Windows

```bash
.\FlightBookingSystem.exe
```

### Linux/macOS

```bash
./FlightBookingSystem
```

## Default Admin

```text
Email    : admin@airline.com
Password : admin123
```

## Notes

- This is intentionally a simple academic project.
- Payment is simulated; no real transaction happens.
- Data is stored using simple `.dat` files.
- Each flight has 20 seats.
- Fixed-size arrays are used instead of advanced containers.
- Password storage is intentionally simple for demonstration.
- The project does not use APIs, databases, networking, or GUI frameworks.
