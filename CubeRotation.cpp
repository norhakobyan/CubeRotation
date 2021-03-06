#include <iostream>
#include <map>
#include <string>
#include <sstream>


struct CubeStruct {
	std::map<std::string, char> cube;
	int coord[3]= { 0 };
	CubeStruct() {

	}
	CubeStruct(std::string str) {
		int len = str.length(),
			len2 = len;
		if (len2 != 8) {
			len2 = 8;
		}
		for (int i = 0; i < len2; ++i) {
			
			 if (i == 1 || i == 2 || i == 5 || i == 6) {
				 this->coord[0] = 1;
			 }
			 else {
				 this->coord[0] = 0;

			 }
			 if (i == 2 || i == 3 || i == 6 || i == 7) {
				 this->coord[1] = 1;
			 }
			 else {
				 this->coord[1] = 0;

			 }
			 if (i > 3) {
				 this->coord[2] = 1;
			 }
			 else {
				 this->coord[2] = 0;
			 }
			 if (i < len) {
				 this->cube[this->key(this->coord)] = str[i] ;
			 }
			 else {
				 this->cube[this->key(this->coord)] =  '&';
			 }

		 }
	}
	void print() {
		std::cout << this->cube["000"] << this->cube["100"] << this->cube["110"] << this->cube["010"];
		std::cout << this->cube["001"] << this->cube["101"] << this->cube["111"] << this->cube["011"];
	}
	void left() {
		this->turnLeft();
		this->turnLeft("1");
	}

	void right() {
		this->turnRight();
		this->turnRight("1");
	}

	void down() {
		this->turnDown();
		this->turnDown("1");
	}

	void up() {
		this->turnUp();
		this->turnUp("1");
	}

	private: 

	std::string key(int *arr) {
		std::string str="";
		for (int i = 0; i < 3; ++i) {
			str+= (char)('0'+arr[i]);
		}
		return str;
	}
	
	void turnLeft(std::string pos = "0") {
		char v1 = this->cube["0"+pos+"0"];
		char v2 = this->cube["0" + pos + "1"];
		char v3 = this->cube["1" + pos + "1"];
		char v4 = this->cube["1" + pos + "0"];

		this->cube["0" + pos + "1"] = v1;
		this->cube["1" + pos + "1"] = v2;
		this->cube["1" + pos + "0"] = v3;
		this->cube["0" + pos + "0"] = v4;
	}

	void turnRight(std::string pos = "0") {
		char v1 = this->cube["0" + pos + "0"];
		char v2 = this->cube["0" + pos + "1"];
		char v3 = this->cube["1" + pos + "1"];
		char v4 = this->cube["1" + pos + "0"];

		this->cube["0" + pos + "1"] = v3;
		this->cube["1" + pos + "1"] = v4;
		this->cube["1" + pos + "0"] = v1;
		this->cube["0" + pos + "0"] = v2;
	}

	void turnDown(std::string pos = "0") {
		char v1 = this->cube[pos + "0" + "0"];
		char v2 = this->cube[pos + "0" + "1"];
		char v3 = this->cube[pos + "1" + "1"];
		char v4 = this->cube[pos + "1" + "0"];

		this->cube[pos + "0" + "1"] = v1;
		this->cube[pos + "1" + "1"] = v2;
		this->cube[pos + "1" + "0"] = v3;
		this->cube[pos + "0" + "0"] = v4;
	}

	void turnUp(std::string pos = "0") {
		char v1 = this->cube[pos + "0" + "0"];
		char v2 = this->cube[pos + "0" + "1"];
		char v3 = this->cube[pos + "1" + "1"];
		char v4 = this->cube[pos + "1" + "0"];

		this->cube[pos + "0" + "1"] = v3;
		this->cube[pos + "1" + "1"] = v4;
		this->cube[pos + "1" + "0"] = v1;
		this->cube[pos + "0" + "0"] = v2;
	}
	
};

int main()
{
	std::string txt;
	std::cout << "ap jan mutqagreq naxadasutyuny vor shifravat enenq" << std::endl;
	std::getline(std::cin, txt);
	std::cout << std::endl;
	int i = 0;
	int j = 0;
	int d = 0;
	CubeStruct * arr = new CubeStruct[10];
	while (true) {
		if (i == 8 ||
			i == 16 ||
			i == 24 ||
			i == 32 ||
			i == 40 ||
			i == 48 ||
			i == 56 ||
			i == 64 ||
			i == 72 ||
			i == 80 ||
			txt[i] == '\0') {
			arr[j] = *new CubeStruct(txt.substr(d, i));
			if (txt[i] == '\0') {
				break;
			}
			d = i;
			++j;
		}
		++i;
	}

	std::string parser;
	std::cout << "ap jan sa inchx kuzis shifravat enis :D" << std::endl;
	std::cin >> parser;
	int v = 0;
	int n = -1;
	while (parser[v] != '\0') {

		if (parser[v] == '0' || 
			parser[v] == '1' ||
			parser[v] == '2' ||
			parser[v] == '3' ||
			parser[v] == '4' ||
			parser[v] == '5' ||
			parser[v] == '6' ||
			parser[v] == '7' ||
			parser[v] == '8') {
			n = parser[v] - '0';
		}

		if (parser[v] == 'L' || parser[v] == 'l') {
			arr[n].left();
		}
		else if (parser[v] == 'R' || parser[v] == 'r') {
			arr[n].right();
		}
		else if (parser[v] == 'U' || parser[v] == 'u') {
			arr[n].up();
		}
		else if (parser[v] == 'D' || parser[v] == 'd') {
			arr[n].down();
		}
		++v;
	}

	for (int k = 0; k <= j; ++k) {
		arr[k].print();
	}
}
