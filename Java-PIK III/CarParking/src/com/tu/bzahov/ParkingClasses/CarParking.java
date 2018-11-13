package com.tu.bzahov.ParkingClasses;

import com.tu.bzahov.Exceptions.CarNotValidException;
import com.tu.bzahov.Exceptions.FullParkingException;
import com.tu.bzahov.VehicleClasses.Car;
import com.tu.bzahov.VehicleClasses.MPS;

public class CarParking extends Parking {
    private int freeStaff;
    private int totalStaff;

    public CarParking(int id, int parkingSlots,int totalStaff) {
        super(id, parkingSlots);
        this.totalStaff = this.freeStaff = totalStaff;
    }

    @Override
    public void park(MPS mps) throws CarNotValidException, FullParkingException {
        if (mps instanceof Car){
            if (freeStaff>0) {
                super.parkNewMPS(mps);
                totalStaff--;
            }
            return;
        }
        throw new  CarNotValidException();
    }
    public void freeStaff(){
        totalStaff++;
    }
}
