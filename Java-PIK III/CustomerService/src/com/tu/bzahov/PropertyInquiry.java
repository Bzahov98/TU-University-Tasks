package com.tu.bzahov;

public class PropertyInquiry {
    private final int id;
    private final String currNameOwner;
    private final String newNameOwner;
    private final String townName;
    private int numberOfRequest = 0;



    public PropertyInquiry(int id, String currNameOwner, String newNameOwner, String townName) {
        this.id = id;
        this.currNameOwner = currNameOwner;
        this.newNameOwner = newNameOwner;
        this.townName = townName;
    }

    public PropertyInquiry(int id, String currNameOwner, String newNameOwner, String townName, int numberOfRequest) {
        this.id = id;
        this.currNameOwner = currNameOwner;
        this.newNameOwner = newNameOwner;
        this.townName = townName;
        this.numberOfRequest = numberOfRequest;
    }

    public int getId() {
        return id;
    }

    public String getCurrNameOwner() {
        return currNameOwner;
    }

    public String getNewNameOwner() {
        return newNameOwner;
    }

    public String getTownName() {
        return townName;
    }

    public int getNumberOfRequest() {
        return numberOfRequest;
    }
}
