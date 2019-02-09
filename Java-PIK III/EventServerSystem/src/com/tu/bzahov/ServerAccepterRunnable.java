package com.tu.bzahov;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.List;

public class ServerAccepterRunnable implements Runnable {
    private Socket socket;
    private ObjectInputStream objectInputStream;
    private ObjectOutputStream objectOutputStream;

    public ServerAccepterRunnable(Socket socket) {
        this.socket = socket;
        try {
            this.objectInputStream = new ObjectInputStream(socket.getInputStream());
            this.objectOutputStream = new ObjectOutputStream(socket.getOutputStream());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        try {
            // read client request
            Message type = (Message) objectInputStream.readObject();
            switch (type.getMessage()) {
                case "showAllEvents":
                    tryAcceptSearch();
                    break;
                case "addNewParticipant":
                    tryAcceptAdditionOfParticipant();
                    break;
                default:
                    System.err.println("Error in task type");
                    break;
            }
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Error");
        }
    }



    private void tryAcceptSearch() throws IOException, ClassNotFoundException {
        Message town = (Message) objectInputStream.readObject();
        Message city = (Message) objectInputStream.readObject();

        List<Event> result = EventStorage.onShowAllEvents(town.getMessage(), city.getMessage());

        objectOutputStream.writeObject(result);
        objectOutputStream.flush();

    }

    private void tryAcceptAdditionOfParticipant() throws IOException, ClassNotFoundException {
        Message id = (Message) objectInputStream.readObject();

        EventStorage.onAddNewParticipant(Integer.parseInt(id.getMessage()));
    }

}
