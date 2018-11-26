package com.tu.bzahov;

public class Person {
    private String firstName;
    private String lastName;
    private String adress;

    public Person(String firstName, String lastName, String adress) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.adress = adress;
    }

    public int myHashCode() {

        int result = ((int)(firstName.hashCode() * Math.sqrt(2.0))
                    + (int)(lastName.hashCode() * Math.sqrt(2.0))
                    + (int)(adress.hashCode() * Math.sqrt(2.0))
        );

        return result;
    }
}
