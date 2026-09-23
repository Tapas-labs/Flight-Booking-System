# Flight Booking System - C++ OOCP Project

A simple console-based Flight Booking System made for an Object-Oriented C++ college project.

## Main Features
- Passenger registration and login
- Admin login
- View all flights
- Search flights by source and destination
- Seat selection
- Flight booking
- Extra baggage calculation
- UPI / Card / Cash payment simulation
- Ticket + PNR generation
- Booking history
- Booking cancellation
- Admin can add/remove flights
- Simple file handling using `.dat` files

## OOP Concepts Demonstrated
- Class and Object
- Encapsulation
- Abstraction
- Inheritance
- Runtime Polymorphism
- Function Overriding
- Constructors / Destructors
- Composition
- STL vector
- File Handling

## 📁 Project Structure

| Path | Description |
|---|---|
| `main.cpp` | Main entry point of the application |
| `classes/User.h` | Base user class |
| `classes/Passenger.h` | Passenger class |
| `classes/Admin.h` | Admin class |
| `classes/Airport.h` | Airport information |
| `classes/Flight.h` | Flight management |
| `classes/Seat.h` | Seat management |
| `classes/Booking.h` | Booking management |
| `classes/Ticket.h` | Ticket and PNR generation |
| `classes/Payment.h` | Payment abstraction |
| `classes/Baggage.h` | Baggage management |
| `implementations/User.cpp` | User class implementation |
| `implementations/Passenger.cpp` | Passenger class implementation |
| `implementations/Admin.cpp` | Admin class implementation |
| `data/flights.dat` | Stores flight data |
| `data/passengers.dat` | Stores passenger data |
| `data/bookings.dat` | Stores booking data |
| `README.md` | Project documentation |


From inside the FlightBookingSystem folder:

g++ -std=c++17 main.cpp implementations/User.cpp implementations/Passenger.cpp implementations/Admin.cpp -o FlightBookingSystem

Run:

Windows:
.\FlightBookingSystem.exe

Linux/macOS:
./FlightBookingSystem

## Default Admin

Email:
admin@airline.com

Password:
admin123

## Notes

- This is intentionally a simple academic project, not a production airline system.
- Payment is simulated; no real transaction happens.
- Data files are simple text files with a `.dat` extension.
- The project uses a maximum of 20 generated seats per flight to keep the logic easy to understand.
- Password storage is intentionally simple for demonstration and should not be used in a real application.
