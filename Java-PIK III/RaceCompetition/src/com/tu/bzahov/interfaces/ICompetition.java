package com.tu.bzahov.interfaces;

import com.tu.bzahov.Participant;

public interface ICompetition{

    Participant[] getSchedule();
    void setSchedule(Participant[] schedule);
}
