package com.tu.bzahov;

import com.tu.bzahov.Exceptions.CarNotValidException;
import com.tu.bzahov.Exceptions.FullParkingException;
import com.tu.bzahov.ParkingClasses.CarParking;
import com.tu.bzahov.ParkingClasses.TruckParking;
import com.tu.bzahov.VehicleClasses.Car;
import com.tu.bzahov.VehicleClasses.Truck;

public class App {

    public static void main(String[] args) {

       try {
           System.out.println("Create Cars:");
               Car car  = new Car("BG1010BZ","a2ab8" ,2001);
               Car car2 = new Car("BG2020BZ","a1a5ab",2011);
          // System.out.println(car instanceof Car);

           System.out.println("Create invalid Car:");
            try {
               Car car3 = new Car("BG1010BZ","ababaaaaaaaaaaaab",2001);
            }catch (CarNotValidException e){
               System.out.println(e.getMessage());
            }

           System.out.println("Create Trucks");
                Truck truck  = new Truck("BG1010BZ","ababab",2001,1);
                Truck truck2 = new Truck("BG2020BZ","ababab",2011,2);
                Truck truck3 = new Truck("BG3030BZ","ababab",2016,3);

           System.out.println("Create Car Parking");
                CarParking carParking  = new CarParking(1,11, 3);
                CarParking carParking2 = new CarParking(2,11, 5);

           System.out.println("Add Car at Car Parking");
                carParking.park(car);
                carParking.park(car2);

           System.out.println("Create Truck Parking");
                TruckParking truckParking  = new TruckParking(1,7);
                TruckParking truckParking2 = new TruckParking(2,3);

           System.out.println("Add Truck at Truck Parking");
                truckParking.park(truck);
                truckParking.park(truck2);
                truckParking.park(truck3);


       }catch (CarNotValidException | FullParkingException e){
            System.out.println(e.getMessage());
        }

    }
}
