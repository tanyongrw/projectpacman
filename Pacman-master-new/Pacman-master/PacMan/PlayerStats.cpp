#include <iostream>
#include <fstream>
#include <string>

struct PlayerStats {
    std::string playerName;
    int score;
    int highScore;

    int getPlayerScore() {
        return score;
    }
};

PlayerStats loadPlayerStats() {
    PlayerStats stats = { "Unknown", 0 }; // กำหนดค่าเริ่มต้น

    std::ifstream inFile("player_stats.txt"); // เปิดไฟล์สำหรับอ่าน
    if (inFile.is_open()) {
        std::getline(inFile, stats.playerName);  // อ่านชื่อผู้เล่น
        inFile >> stats.score;                   // อ่านคะแนน
        inFile.close();                          // ปิดไฟล์
    }
    else {
        std::cout << "Error: Unable to open file for loading stats.\n";
    }

    return stats;  // คืนค่าข้อมูลผู้เล่น
}

void savePlayerStats(const PlayerStats& stats) {
    std::ofstream outFile("player_stats.txt"); // เปิดไฟล์สำหรับเขียน
    if (outFile.is_open()) {
        outFile << "Player: " << stats.playerName << "\n";
        outFile << "Score: " << stats.score << "\n";
        outFile.close();
    }
    else {
        std::cout << "Error: Unable to open file for saving stats.\n";
    }
}