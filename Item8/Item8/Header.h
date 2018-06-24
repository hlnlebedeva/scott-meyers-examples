
class Widget
{
private:
	int* a;

	
public:
	Widget() 	{ 

		a = new int[10000]; };

	~Widget() noexcept(false)
	{
		std::cout << "Destructor of Widget\n";
		delete[] a;
		throw "error";
	}

};

class DBConnectException
{};

extern class DBConnection;

class DBConnection
{
private:
	std::string conString;
public:
	DBConnection()
	{}

	DBConnection(std::string str)
	{
		conString = str;
	}

	static DBConnection create(std::string str)
	{
		DBConnection con(str);
		return con;
	};

	void close() 
	{ 
		if (conString.empty())
		{
			DBConnectException e;
			throw e;
		}
		else
		{
			conString.erase();
		}
		
	};
};

class DBConn
{
public:
	DBConn(DBConnection conn)
	{
		db = conn;
	};

	~DBConn()
	{
		if (!closed)
		{
			try
			{
				db.close();
			}
			catch (...)
			{
			}
		}
	};

	void close()
	{
		db.close();
		closed = true;
	};

private:
	DBConnection db;
	bool closed;
};
