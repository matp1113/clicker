#include "player.h"

#include <QDebug>
#include <regex>
#include <QDir>
#include <QFile>
#include <fstream>
#include <iostream>

Player::Player(QObject *parent)
    : QObject{parent}
{
    qDebug() << QDir().absolutePath();
}

void Player::setName(QString name)
{
    _name = name;
}

void Player::setTime(QString time)
{
    _time = time;
    save();
}

void Player::setSupport(int support)
{
    _support = support;
}

void Player::save()

{
    QFile file("C:/Users/Mateusz/Desktop/soft_int_qt/build-clicker-Desktop_Qt_6_3_1_MinGW_64_bit-Debug/results.txt");

    if(file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
    {
        QTextStream stream(&file);

        stream << _name << " , " << _time << " , " << _support << '\n';

        file.close();
        qDebug() << "Writing finished";
    }

    sort();
}

void Player::sort()
{
    qDebug() << "now I am sorting";
    try{
        auto StrTrim = [](std::string & str){
            str.erase(0, str.find_first_not_of("\t\n\v\f\r "));
            str.erase(str.find_last_not_of("\t\n\v\f\r ") + 1);
        };
        std::ifstream ifile("C:/Users/Mateusz/Desktop/soft_int_qt/build-clicker-Desktop_Qt_6_3_1_MinGW_64_bit-Debug/results.txt");
        std::string line;
        std::vector<std::string> lines;

        while(std::getline(ifile, line)){
            StrTrim(line);
            if(line.empty()){
                continue;
            }
            lines.push_back(line);
        }
        if(!lines.empty()){
            lines.erase(lines.begin(), lines.begin() + 1);
        }
        lines.erase(lines.begin(), lines.begin() + 1);

        std::vector<std::tuple<std::string, std::string, size_t>> data;
        std::regex re(R"((\w+)\s+,\s+(\d.\d+.\d+)\s,\s(\d+))");

        for(auto const & line: lines){
            std::smatch matches;
            if(std::regex_match(line, matches, re)){
                qDebug() << "matches size: " << matches.size();
                if(matches.size() != 4){
                    throw std::runtime_error("Matched line with not 3 elements: " + line);
                }
                data.push_back(std::make_tuple(matches[1], matches[2], size_t(std::stoi(matches[3]))));
            }
            else{
                throw std::runtime_error("Unmatched line: " + line);
            }
        }
        std::sort(data.begin(), data.end(), [](auto const & l, auto const & r){
            return std::get<2>(l) > std::get<2>(r);
        });
        std::cout << "updated rankung:" << std::endl;
        for(size_t i = 0; i < 5; ++i){
            if(i >= data.size()){
                break;
            }
            std::cout << (i+1) << "|" << std::get<0>(data[i]) << ", " << std::get<1>(data[i]) << ", " << std::get<2>(data[i]) << std::endl;
        }
    }
    catch(std::exception const & ex){
        std::cout << "Exception: " << ex.what() << std::endl;
    }

}
