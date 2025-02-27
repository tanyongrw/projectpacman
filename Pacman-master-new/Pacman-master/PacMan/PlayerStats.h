#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <iostream>
#include <fstream>
#include <string>

struct PlayerStats {
    std::string playerName; // ชื่อผู้เล่น
    int score;              // คะแนนที่ทำได้

    int getPlayerScore() const { return score; }
};

// โหลดข้อมูลผู้เล่นจากไฟล์
PlayerStats loadPlayerStats();

// บันทึกข้อมูลผู้เล่นลงไฟล์
void savePlayerStats(const PlayerStats& stats);

#endif // PLAYERSTATS_H
