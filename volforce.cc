#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

double VS[21];
double RS[21];
struct Data {

	Data() {}
	Data(const Data& d)
	{
		this->score = d.score;
		this->track_name = d.track_name;
		this->V = d.V;
		this->r = d.r;
		this->level = d.level;
	}
	Data(string t_n, int s, int l, double v, double _r) : track_name(t_n), level(l), V(v), r(_r) {}
	Data(string t_n, int s, int l) : track_name(t_n), score(s), level(l)
	{
		V = VS[l+1] * RS[l+1] * pow((double)score / pow(10, 7), level);
	}
	string track_name;
	int score;
	int level;
	double V;
	double r;
};

vector<Data> myData;

ostream& operator<<(ostream& os, const Data& d)
{
	os << "\"" << d.track_name << "\"\'s" << "skill point of the track: " << (double)((int)(d.V * 100.0 + 0.5)) / 100.0;
	return os;
}

void initialize()
{
	VS[19] = 500.0;
	for(int i = 20; i > 0; --i)
	{
		RS[i] = 1.0 / pow((double)i, 1.0 / i);
	}
	for(int i = 18; i > 0; --i)
	{
		VS[i] = VS[i+1] * RS[i+1];
	}
	VS[20] = VS[19] / RS[20];
}

int main()
{
	string track_name;
	int level, score;
	initialize();
	for(int i = 1; i <= 20; ++i)
	{
		printf("(%d/20) - ", i);
		cout << "(level track_name score) > ";
		cin >> level >> track_name >> score;
		Data track(track_name, score, level);
		cout << track << "\n";
		myData.push_back(track);
	}
	return 0;
}
