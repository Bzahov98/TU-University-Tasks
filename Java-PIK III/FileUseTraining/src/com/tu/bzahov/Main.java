package com.tu.bzahov;

import java.awt.*;
import java.io.*;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        final String pathTxt = "/home/bobo/";
        final String fileTxt = "newFile.txt";
        final String bothInput = pathTxt + fileTxt;
        final String bothOutput = pathTxt + fileTxt;

        File file = new File(bothInput);
        try {
            boolean isCreated = file.createNewFile();
            if (isCreated){
                System.out.println("Successfully created file   ");
            }else System.out.println("File Exists");
        } catch (IOException e) {
            System.out.println(e.getMessage());;
        }

        try {
            FileInputStream in = new FileInputStream(bothInput);
            FileOutputStream out = new FileOutputStream(bothOutput);
            int c;

            while ((c = in.read())!= 1){
                out.write(c);
            }

            if(in!= null)in.close();
            if(out!= null)out.close();

        } catch (IOException e) {
            e.printStackTrace();

        }

        ArrayList<User> arrayList = new ArrayList<>();
        arrayList.add(new User("Pesho","Georgiev"));
        arrayList.add(new User("Pesho2","Georgiev2"));
        arrayList.add(new User("Pesho3","Georgiev3"));

        /*for (int i = 0; i< arrayList.size();i++){
            userArr[i] =
        }*/
        try {
            FileOutputStream out = new FileOutputStream(bothOutput);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
       // ObjectInputStream ois = new ObjectInputStream(new FileInputStream("test.txt"));


      /*  try {
         //   ObjectInputStream objectInput = new ObjectInputStream();
        } catch (IOException e ) {
            e.printStackTrace();
        }
*/
    }
}
