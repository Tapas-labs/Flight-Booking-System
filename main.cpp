#include <iostream>
#include <fstream>
#include <string.h>
#include "classes/Passenger.h"
#include "classes/Admin.h"
#include "classes/Flight.h"
#include "classes/Booking.h"
#include "classes/Baggage.h"
#include "classes/Ticket.h"
#include "classes/Payment.h"
using namespace std;


Flight flights[10]; 
int flightCount=0;

Passenger passengers[50]; 
int passengerCount=0;

Booking bookings[100]; 
int bookingCount=0;

Admin admin(1,"System Admin","admin@gmail.com","admin123","9999999999","ADM001","Flight Manager");


int input()
{
    int x;
    cin>>x;
    cin.ignore(1000,'\n');
    return x;}

void text(char a[],int n)
{
    cin.getline(a,n);
}

void savePassengers(){
    ofstream f("data/passengers.dat");
    for(int i=0;i<passengerCount;i++)
        f<<passengers[i].getUserId()<<'\n'<<passengers[i].getName()<<'\n'<<passengers[i].getEmail()<<'\n'<<passengers[i].getPassword()<<'\n'<<passengers[i].getPhone()<<'\n'<<passengers[i].getPassportNo()<<'\n';
    f.close();
}

void loadPassengers(){
    ifstream f("data/passengers.dat"); 
    if(!f)return;
    int id; 
    char n[50],e[50],p[30],ph[20],pass[30];
    while(f>>id){
        f.ignore(1000,'\n'); f.getline(n,50); f.getline(e,50); f.getline(p,30); f.getline(ph,20); f.getline(pass,30);
        passengers[passengerCount++]=Passenger(id,n,e,p,ph,pass,20);
        if(passengerCount>=50)break;
    } f.close();
}

void saveFlights(){
    ofstream f("data/flights.dat");
    for(int i=0;i<flightCount;i++)
        f<<flights[i].getId()<<'\n'<<flights[i].getNumber()<<'\n'
         <<flights[i].getAirline()<<'\n'<<flights[i].getSource()<<'\n'
         <<flights[i].getDestination()<<'\n'<<flights[i].getDeparture()<<'\n'
         <<flights[i].getArrival()<<'\n'<<flights[i].getFare()<<'\n';
    f.close();
}

void loadFlights(){
    ifstream f("data/flights.dat");
    if(!f)return;
    int id;
     char no[20],air[40],s[40],d[40],dep[20],arr[20]; 
     double fare;
    while(f>>id){
        f.ignore(1000,'\n');
        f.getline(no,20); f.getline(air,40); f.getline(s,40); f.getline(d,40);
        f.getline(dep,20); f.getline(arr,20); f>>fare;
        f.ignore(1000,'\n');
        flights[flightCount++]=Flight(id,no,air,s,d,dep,arr,fare);
        if(flightCount>=10)break;
    }
    f.close();
}

void saveBookings(){
    ofstream f("data/bookings.dat");
    for(int i=0;i<bookingCount;i++)
        f<<bookings[i].getId()<<'\n'<<bookings[i].getPassengerId()<<'\n'
         <<bookings[i].getFlightId()<<'\n'<<bookings[i].getSeat()<<'\n'
         <<bookings[i].getPassengerName()<<'\n'<<bookings[i].getFlightNumber()<<'\n'
         <<bookings[i].getAmount()<<'\n'<<bookings[i].getPNR()<<'\n'
         <<bookings[i].getStatus()<<'\n';
    f.close();
}

void loadBookings(){
    ifstream f("data/bookings.dat");
    if(!f)return;
    int id,pid,fid,seat; 
    char pa[50],fl[20],pnr[20],status[20]; 
    double amount;
    while(f>>id>>pid>>fid>>seat){
        f.ignore(1000,'\n');
        f.getline(pa,50); f.getline(fl,20); f>>amount; f.ignore(1000,'\n');
        f.getline(pnr,20); f.getline(status,20);
        bookings[bookingCount++]=Booking(id,pid,fid,seat,pa,fl,amount,pnr);
        if(strcmp(status,"Cancelled")==0) bookings[bookingCount-1].cancel();
        if(strcmp(status,"Confirmed")==0){
            for(int j=0;j<flightCount;j++) if(flights[j].getId()==fid) flights[j].bookSeat(seat);
        }
        if(bookingCount>=100)break;
    }
    f.close();
}
void defaults(){
    ifstream f("data/flights.dat");
    bool exists=(bool)f; 
    f.close();
    if(exists)
    {loadFlights();
        if(flightCount>0)
        return;
    }
    flightCount=3;
    flights[0]=Flight(101,"AI203","Air India","Ahmedabad","Delhi","10:30","12:15",4500);
    flights[1]=Flight(102,"6E501","IndiGo","Ahmedabad","Mumbai","14:00","15:15",3000);
    flights[2]=Flight(103,"SG102","SpiceJet","Delhi","Ahmedabad","17:30","19:00",4200);
    saveFlights();
}

void showFlights()
{
    for(int i=0;i<flightCount;i++)
    flights[i].display();
}

void registerPassenger()
{
    if(passengerCount>=50)
    return;
    char n[50],e[50],p[30],ph[20],pass[30];
    cout<<"Name: ";text(n,50); 
    cout<<"Email: ";text(e,50); 
    cout<<"Password: ";text(p,30);
    cout<<"Phone: ";text(ph,20); 
    cout<<"Passport: ";text(pass,30);
    int id=101+passengerCount;
    passengers[passengerCount++]=Passenger(id,n,e,p,ph,pass,20);
    savePassengers(); cout<<"Registered. Passenger ID: "<<id<<"\n";
}
void history(int pid){
    bool found=false;
    for(int i=0;i<bookingCount;i++)
    if(bookings[i].getPassengerId()==pid)
    {
        bookings[i].display();found=true;
    }
    if(!found)cout<<"No bookings.\n";
}

void book(int pi)
{
    showFlights(); 
    cout<<"Flight ID: "; 
    int id=input(); 
    int fi=-1;
    for(int i=0;i<flightCount;i++)
    if(flights[i].getId()==id)
    fi=i;
    if(fi<0)
    {
        cout<<"Invalid flight.\n";
        return;
    }
    flights[fi].showSeats(); 
    cout<<"Seat (1-20): "; 
    int seat=input();
    if(!flights[fi].seatAvailable(seat)||!flights[fi].bookSeat(seat))
    {
        cout<<"Seat unavailable.\n";
        return;
    }
    cout<<"Baggage KG: "; 
    int w=input(); 
    Baggage b(w); 
    b.display();
    double total=flights[fi].getFare()+b.getCharge();
    cout<<"Total: Rs. "<<total<<"\n1.UPI 2.Card 3.Cash\nChoice: ";
    int c=input();
    Payment* pay=0; 
    char data[50];
    if(c==1)
    {
        cout<<"UPI ID: ";
        text(data,50);
        pay=new UPIPayment(total,data);
    }
    else if(c==2)
    {
        cout<<"Card Number: ";
        text(data,50);
        pay=new CardPayment(total,data);
    }
    else if(c==3)pay=new CashPayment(total);
    
    else
    {
        cout<<"Invalid payment.\n";
        flights[fi].cancelSeat(seat);
        return;
    }
    pay->pay();delete pay;
    
    int bid=1001+bookingCount;
    char pnr[20];
    strcpy(pnr,"PNR");
    char num[10]; 
    int n=bid,j=0;
    while(n)
    {
        num[j++]=char('0'+n%10);
        n/=10;
    }
    for(int k=0;k<j/2;k++)
    {
        char t=num[k];
        num[k]=num[j-k-1];
        num[j-k-1]=t;
    }
    num[j]='\0';
    strcat(pnr,num);
    bookings[bookingCount++]=Booking(bid,passengers[pi].getUserId(),id,seat,passengers[pi].getName(),flights[fi].getNumber(),total,pnr);
    saveBookings(); Ticket t(bid,pnr,passengers[pi].getName(),flights[fi].getNumber(),seat,total);t.display();
}
void cancel(int pid)
{
    history(pid); 
    cout<<"Booking ID: ";
    int id=input();
    for(int i=0;i<bookingCount;i++)
    if(bookings[i].getId()==id&&bookings[i].getPassengerId()==pid)
    {
        if(strcmp(bookings[i].getStatus(),"Cancelled")==0){
            cout<<"Already cancelled.\n";
            return;}
        for(int j=0;j<flightCount;j++)
        if(flights[j].getId()==bookings[i].getFlightId())flights[j].cancelSeat(bookings[i].getSeat());
        bookings[i].cancel();saveBookings();
        cout<<"Booking cancelled.\n";
        return;
    } 
    cout<<"Booking not found.\n";
}

void passengerMenu(int pi)
{
    int c;
    do{
        cout<<"\n--- Passenger Menu ---\n1.Profile\n2.All Flights\n3.Search\n4.Book\n5.History\n6.Cancel\n7.Logout\nChoice: ";c=input();
        if(c==1)passengers[pi].displayProfile();
        else if(c==2)showFlights();
        else if(c==3){char a[40],b[40];
            cout<<"Source: ";text(a,40);
            cout<<"Destination: ";
            text(b,40);
            for(int i=0;i<flightCount;i++)
            if(flights[i].matches(a,b))flights[i].display();
        }
        else if(c==4)book(pi);
        else if(c==5)history(passengers[pi].getUserId());
        else if(c==6)cancel(passengers[pi].getUserId());
        else if(c==7)passengers[pi].logout();
        else cout<<"Invalid choice.\n";
    }
    while(c!=7);
}
void passengerLogin(){
    char e[50],p[30];
    cout<<"Email: ";
    text(e,50);
    cout<<"Password: ";
    text(p,30);
    for(int i=0;i<passengerCount;i++)
    if(passengers[i].login(e,p))
    {
        cout<<"Login successful.\n";
        passengerMenu(i);
        return;
    }
    cout<<"Invalid login.\n";
}
void addFlight(){
    int id;
    char no[20],air[40],s[40],d[40],dep[20],arr[20];
    double fare;
    cout<<"ID: ";
    id=input();
    cout<<"Number: ";
    text(no,20);
    cout<<"Airline: ";
    text(air,40);
    cout<<"Source: ";
    text(s,40);
    cout<<"Destination: ";
    text(d,40);
    cout<<"Departure: ";
    text(dep,20);
    cout<<"Arrival: ";
    text(arr,20);
    cout<<"Fare: ";
    cin>>fare;
    cin.ignore(1000,'\n');
    flights[flightCount++]=Flight(id,no,air,s,d,dep,arr,fare);
    saveFlights();
    cout<<"Flight added.\n";
}
void removeFlight(){
    showFlights();
    cout<<"Flight ID: ";
    int id=input();
    for(int i=0;i<flightCount;i++)
    if(flights[i].getId()==id)
    {
        for(int j=i;j<flightCount-1;j++)
        flights[j]=flights[j+1];
    flightCount--;
    saveFlights();
    cout<<"Removed.\n";
    return;}
    cout<<"Not found.\n";
}

void adminMenu(){
    int c;
    do{
        cout<<"\n--- Admin Menu ---\n1.Profile\n2.Flights\n3.Add Flight\n4.Remove Flight\n5.All Bookings\n6.Logout\nChoice: ";c=input();
        if(c==1)admin.displayProfile();
        else if(c==2)showFlights();
        else if(c==3)addFlight();
        else if(c==4)removeFlight();
        else if(c==5)
        {
            for(int i=0;i<bookingCount;i++)
            bookings[i].display();
        }
        else if(c==6)admin.logout();
        else cout<<"Invalid choice.\n";
    }
    while(c!=6);
}
void adminLogin(){
    char e[50],p[30];cout<<"Email: ";
    text(e,50);
    cout<<"Password: ";
    text(p,30);
    if(admin.login(e,p))
    {
        cout<<"Login successful.\n";
        adminMenu();
    }
    else cout<<"Invalid login.\n";
}
int main(){
    defaults();
    loadPassengers();
    loadBookings();
    cout<<"=================================\n   FLIGHT BOOKING SYSTEM\n=================================\n";
    int c;
    do{
        cout<<"\n1.Register Passenger\n2.Passenger Login\n3.Admin Login\n4.View Flights\n5.Exit\nChoice: ";c=input();
        if(c==1)registerPassenger();
        else if(c==2)passengerLogin();
        else if(c==3)adminLogin();
        else if(c==4)showFlights();
        else if(c==5)cout<<"Thank you.\n";
        else cout<<"Invalid choice.\n";
    }
    while(c!=5);
    return 0;
}
