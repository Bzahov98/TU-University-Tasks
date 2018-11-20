package com.tu.bzahov;

public class Participant {
    private final int participantId;
    private final int participantAge;
    private final String participantName;
    private double chanceForWin;
    private double betForWin;

    public Participant(int participantId, int participantAge, String participantName) {
        this.participantId = participantId;
        this.participantAge = participantAge;
        this.participantName = participantName;
        this.chanceForWin = 0;
        this.betForWin = 0;
    }

    public void setChanceForWin(double chanceForWin) {
        this.chanceForWin = chanceForWin;
    }

    public double getChanceForWin() {
        return chanceForWin;
    }

    public double getBetForWin() {
        return betForWin;
    }

    public void setBetForWin(double betForWin) {
        this.betForWin = betForWin;
    }
}
