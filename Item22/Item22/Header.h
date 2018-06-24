#pragma once

class AccessLevels
{
public:
	int getReadOnly() const { return readOnly; }

	void setReadWrite(int value) { readWrite = value; }
	int getReadWrite() const { return readWrite; }

	void setWriteOnly(int value) { writeOnly = value; }
private:
	int noAccess;	// no access ti thid int
	int readOnly;	// read-only access to thid int
	int readWrite;	// read-write access ti this int
	int writeOnly;  // write-only access ti this int
};


class SpeedDataCollection
{
public:
	SpeedDataCollection() //: average(0) 
	{}
	void addValue(int speed); // add a new data value
	double averageSoFar() const; // return average speed

private:
	//double average;
	std::list<int> speedValues;
};