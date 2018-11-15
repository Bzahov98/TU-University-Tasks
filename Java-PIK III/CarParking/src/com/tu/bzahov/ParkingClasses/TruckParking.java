package com.tu.bzahov.ParkingClasses;

import com.tu.bzahov.Exceptions.CarNotValidException;
import com.tu.bzahov.Exceptions.FullParkingException;
import com.tu.bzahov.VehicleClasses.MPS;
import com.tu.bzahov.VehicleClasses.Truck;

import java.util.ArrayList;

public class TruckParking extends Parking {
    public TruckParking(int id, int parkingSlots) {
        super(id, parkingSlots);
    }

    @Override
    public void park(MPS mps) throws CarNotValidException, FullParkingException {
        if (mps instanceof Truck){
            if (mpsList == null){
                mpsList = new ArrayList<>();
            }
            int truckSize = ((Truck) mps).getSize();
            int totalVehicleSize = mpsList.size()+ truckSize;

            if (totalVehicleSize < allParkingSlots){
                mpsList.add(mps);
                allUsedParkingSlots+= totalVehicleSize ;
            }else throw new FullParkingException();
            return;
        } throw new CarNotValidException();
    }
}
