package com.tu.bzahov;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
	    Person person1 = new Person("Ivan", "Ivanov","Sofia");
	    Person person2 = new Person("Gosho", "Ivanov","Sofia-Oblast");
	    Person person3 = new Person("Pesho", "Ivanov","Sofia");
	    Person person4 = new Person("Bojo", "Georgiev","Sofia-Grad");

	    HashMap<Integer,Person> hashMap = new HashMap<>();
        hashMap.put(1,person1);
        hashMap.put(2,person2);
        hashMap.put(3,person3);
        hashMap.put(4,person4);

        Set set = hashMap.entrySet();
        Iterator iterator = set.iterator();
        while(true) {
            Map.Entry mentry;
            if (iterator.hasNext()) {
                mentry = (Map.Entry) iterator.next();
            }else break;
            System.out.print("key is: "+ mentry.getKey() + " & Value is: ");
            Person curPerson =(Person) mentry.getValue();
            System.out.println((curPerson).myHashCode());
        }

        /*while(iterator.hasNext()) {
            Map.Entry mEntry = (Map.Entry)iterator.next();
            System.out.print("key is: "+ mEntry.getKey() + " & Value is:" + mEntry.getValue());
            (Person) mEntry.getValue().equals(( iterator.next()).getValue());
        }*/
    }
}
