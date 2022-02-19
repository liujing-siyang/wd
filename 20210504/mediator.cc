 ///
 /// @file    mediator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-04 17:27:31
 ///
 
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::string;


class Building
{
public:
	Building(const string & quality)
	: _quality(quality)
	{}

	virtual void sale() = 0;
	virtual string getQualitiy() = 0;
	virtual ~Building() {}
protected:
	string _quality;
};


class WankeBuildig
: public Building
{
public:
	WankeBuildig(const string & quality)
	: Building(quality)
	{}

	void sale() 
	{
		cout << _quality << " 万科楼盘被售卖\n";
	}

	string getQualitiy() {	return _quality;	}
};

 
class LanguangBuildig
: public Building
{
public:
	LanguangBuildig(const string & quality)
	: Building(quality)
	{}

	void sale() 
	{
		cout << _quality << " 蓝光楼盘被售卖\n";
	}

	string getQualitiy() {	return _quality;	}
};

class Mediator
{
public:
	Mediator()
	{
		Building * wanke = new WankeBuildig("高品质");
		Building * languang = new LanguangBuildig("低品质");
		_buildings.push_back(wanke);
		_buildings.push_back(languang);
	}

	Building * findBuilding(const string & demand)
	{
		for(auto & building : _buildings) {
			if(building->getQualitiy() == demand) {
				return building;
			}
		}
		return nullptr;
	}

	void getNewBuilding(Building * building)
	{
		if(building != nullptr) {
			_buildings.push_back(building);
		}
	}

private:
	vector<Building*> _buildings;
};


void test0() 
{
	string demand = "中品质";
	Mediator mediator;
	Building * building = mediator.findBuilding(demand);
	if(building) {
		building->sale();
	} else {
		cout << "未找到与需求符合的楼盘" << endl;
	}
} 
 
int main(void)
{
	test0();
	return 0;
}
