#include "stdafx.h"

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

#include <sstream>
#include <fstream>

#include <numeric>

//void PrintIntegers(std::istream& in, std::ostream& out);
void PrintMaxFloat(std::istream& in, std::ostream& out);

int main()
{
	//std::ofstream test("test.txt");
	//test << "abcd\n" << std::endl << std::endl << "\nA\nB\nC";
	//std::string strTest;
	//std::ifstream ttt("test.txt");
	//파일 스트림을 가지고 A B C
	//(ttt.peek() != EOF) 파일 디스크립터 위치가 EOF인지
	//while (std::getline(ttt, strTest))
	//{
	//	std::cout << strTest << std::endl;
	//}
	//std::ifstream inInt("PrintIntegersIn.txt");
	//std::ofstream outInt("PrintIntegersOut.txt");
	//PrintIntegers(inInt, outInt);

	std::ifstream inFloat("PrintMaxFloatIn.txt");
	std::ofstream outFloat("PrintMaxFloatOut.txt");
	PrintMaxFloat(inFloat, outFloat);
	return 0;
}

//void PrintIntegers(std::istream& in, std::ostream& out)
//{
//	out << std::setw(12) << std::right << "oct" << std::setw(11) << "dec" << std::setw(9) << "hex" << std::endl;
//	out << std::setfill('-') << std::setw(13) << ' ' << std::setw(11) << ' ' << std::setw(8) << '-' << std::setfill(' ') << std::endl;
//
//	int number = 0;
//	std::string trash;
//	while (in.eof() == false)
//	{
//		in >> number;
//
//		if (in.fail() == true)
//		{
//			in.clear();
//			in >> trash;
//		}
//		else
//		{
//			//8진수 변환 및 입력
//			out << std::setw(12) << std::right << std::oct << number;
//
//			//10진수
//			out << std::setw(11) << std::right << std::dec << number;
//
//			//16진수 변환 및 입력
//			out << std::setw(9) << std::right << std::uppercase << std::hex << number << std::endl;
//		}
//	}
//}

void printintegers(std::istream& in, std::ostream& out)
{
	//입력
	std::stringstream ss;
	std::string line;

	std::string separatestr;
	while (std::getline(in, line))
	{
		for (auto it = line.begin(); it != line.end(); ++it)
		{
			if (*it >= 48 && *it <= 57)
			{
				separatestr += *it;
			}
			if (separatestr.empty() == false &&
				(it + 1 == line.end() || *it < 48 || *it > 57))
			{
				separatestr += ' ';
			}
		}
	}
	ss.str(separatestr);

	out << std::setw(12) << std::right << "oct" << std::setw(11) << "dec" << std::setw(9) << "hex" << std::endl
		<< std::setfill('-') << std::setw(13) << ' ' << std::setw(11) << ' ' << std::setw(8) << '-' << std::setfill(' ') << std::endl;

	uint32_t num;
	while (ss >> num)
	{
		//8진수 변환 및 입력
		out << std::setw(12) << std::right << std::oct << num;
		//10진수
		out << std::setw(11) << std::right << std::dec << num;
		//16진수 변환 및 입력
		out << std::setw(9) << std::right << std::uppercase << std::hex << num << std::endl;;
	}
}

/* PrintIntegers 끝, PrintMaxFloat 시작 */

void PrintMaxFloat(std::istream& in, std::ostream& out)
{
	int number = 0;
	std::string trash;
	std::numeric_limits <float>::max() * -1;
	float maxValue = -FLT_MAX;
	while (in.eof() == false)
	{
		//1.2 2.2 2.aa 3ff
		//겟라인예제필요함
		캐릭터 컨트롤 블럭 
			aaaa\n\n\n\n\n\nbbbb\n\n\n\n\n\n\dfda
			aaaabbbbdfda
		in >> number;
		배드비트는 문제가 있다
			일반적인 상황에서 예외처리가 되어있기 때문에 페일비트만 고려하면 된다.;

		if (in.fail() == true)
		{
			in.clear();
			in >> trash;
		}
		else
		{
			if (maxValue < number)
			{
				maxValue = number;
			}

			out << "     " << std::showpos << std::internal << std::fixed << std::setprecision(3) << std::setw(15) << number << std::endl;
		}
	}

	out << "max: " << std::internal << std::setw(15) << maxValue << std::endl;
}

//void PrintMaxFloat(std::istream& in, std::ostream& out)
//{
//	//입력
//	std::stringstream ss;
//	std::string separateStr;
//	std::string line;
//	while (std::getline(in, line))
//	{
//		for (auto it = line.begin(); it != line.end(); ++it)
//		{
//			if ((*it >= 48 && *it <= 57) || *it == 46 || *it == 45 || *it == 43)
//			{
//				if (separateStr.empty() == true && *it == 46)
//				{
//					continue;
//				}
//				if ((separateStr.empty() == false) &&
//					(*it == 45 || *it == 43) &&
//					(separateStr.back() == 45 || separateStr.back() == 43))
//				{
//					separateStr.back() = *it;
//					continue;
//				}
//				separateStr += *it;
//			}
//			if (separateStr.empty() == false &&
//				(it + 1 == line.end() || (*it < 48 || *it > 57)))
//			{
//				if (*it == 46 || separateStr.back() == 32 || separateStr.back() == 45 || separateStr.back() == 43) continue;
//
//				separateStr += ' ';
//			}
//		}
//	}
//	ss.str(separateStr);
//
//	//출력
//	float maxNum = -99999999;
//	float num = 0;
//	while (ss >> num)
//	{
//		if (num > maxNum)	//최댓값
//		{
//			maxNum = num;
//		}
//
//		out << "     " << std::showpos << std::internal <<
//			std::fixed << std::setprecision(3) << std::setw(14) << num << std::endl;
//	}
//	out << "max: " << std::internal << std::setw(14) << maxNum << std::endl;
//}