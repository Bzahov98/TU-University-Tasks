package com.tu.bzahov.ParkingClasses;

import com.tu.bzahov.Exceptions.CarNotValidException;
import com.tu.bzahov.Exceptions.FullParkingException;
import com.tu.bzahov.VehicleClasses.MPS;

import java.util.ArrayList;
import java.util.Iterator;

public abstract class Parking {
    private int id;
    protected int allParkingSlot;
    protected ArrayList<MPS> mpsList;
    protected static int allParkingSlots;
    protected static int allUsedParkingSlots;


    public Parking(int id, int parkingSlots) {
        this.id = id;
        this.allParkingSlot = parkingSlots;
        allParkingSlots += parkingSlots;
    }


    public void parkNewMPS(MPS mps) throws FullParkingException{
        if (mpsList == null){
            mpsList=new ArrayList<MPS>();
        }

        if (mpsList.size() < allParkingSlots){
            mpsList.add(mps);
            allUsedParkingSlots++;
            System.out.println("New vehicle: "+ mps.toString() +" has been parked!");
        }else throw new FullParkingException();
    }

    public void removeMPSbyData(String mpsData){
        if (mpsList == null || mpsList.isEmpty()){
            return;
        }
        Iterator<MPS> i = mpsList.iterator();
        while (i.hasNext()) {
            MPS currentMPS = i.next(); // must be called before you can call i.remove()
            if (currentMPS.toString().equals(mpsData)){
                System.out.println(mpsData + " has been removed successfully");
                i.remove();
                allUsedParkingSlots--;
            }
        }
    }
    public int freeSlotsNumber(){
        return allParkingSlots - allUsedParkingSlots;
    }

    public int busySlotsNumber(){
        return allUsedParkingSlots;
    }

    public abstract void park(MPS mps)throws CarNotValidException, FullParkingException;

}
