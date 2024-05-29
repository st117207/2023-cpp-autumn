#include <iostream>

class Subject
{
public:
	Subject();
	Subject(std::string name);
	Subject(const Subject& other);
	Subject(Subject&& other);
	~Subject();
	Subject operator=(Subject other);
	bool operator<(Subject other);
	bool operator==(Subject other);
	bool operator>(Subject other);
	bool operator<=(Subject other);
	bool operator>=(Subject other);
	bool operator!=(Subject other);
	//Subject operator+=(int mark);
	//std::string toString();

private:
	friend std::ostream& operator<<(std::ostream& stream, const Subject& subject);
	void dispose();
	std::string _name;
	int* _marks;
	int _markscount;
};

Subject::Subject()
{
	_name = "";
	_markscount = 0;
	_marks = nullptr;
}

Subject::Subject(std::string name)
{
	_name = name;
	_markscount = 0;
	_marks = nullptr;
}

Subject::Subject(const Subject& other)
{
	_name = other._name;
	_markscount = other._markscount;
	if (_markscount > 0)
	{
		_marks = new int[_markscount];
		if (_marks != nullptr)
		{
			for (int i = 0; i < _markscount; ++i)
			{
				_marks[i] = other._marks[i];
			}
		}
		else
		{
			_markscount = 0;
		}
	}
}

Subject::Subject(Subject&& other)
{
	_name = other._name; //std::move
	_markscount = other._markscount;
	_marks = other._marks;
	other._name = "";
	other._marks = nullptr;
	other._markscount = 0;
}

Subject::~Subject()
{
	dispose();
}

Subject Subject::operator=(Subject other)
{
	dispose();
	_name = other._name;
	_markscount = other._markscount;
	if (_markscount > 0)
	{
		_marks = new int[_markscount];
		if (_marks != nullptr)
		{
			for (int i = 0; i < _markscount; ++i)
			{
				_marks[i] = other._marks[i];
			}
		}
		else
		{
			_markscount = 0;
		}
	}
	return other;
}

bool Subject::operator==(Subject other)
{
	return !(*this != other);
}

bool Subject::operator<(Subject other)
{
	if (_name < other._name)
	{
		return true;
	}
	else if (_name > other._name)
	{
		return false;
	}

	if (_markscount < other._markscount)
	{
		return true;
	}
	else if (_markscount > other._markscount)
	{
		return false;
	}

	int s = 0;
	int os = 0;
	for (int i = 0; i < _markscount; ++i)
	{
		s += _marks[i];
		os += other._marks[i];
	}

	if (s < os)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Subject::operator>(Subject other)
{
	return (other < *this);
}

bool Subject::operator<=(Subject other)
{
	return ((*this < other) || (*this == other));
}

bool Subject::operator>=(Subject other)
{
	return (other >= *this);
}

bool Subject::operator!=(Subject other)
{
	return ((*this > other) || (*this < other));
}

void Subject::dispose()
{
	_name = "";
	if (_marks != nullptr)
	{
		_markscount = 0;
		delete[] _marks;
	}
}

int main()
{
	Subject s;
	Subject d;
	if (s == d)
	{
		std::cout << "b";
	}
	return EXIT_SUCCESS;
}
std::ostream& operator<<(std::ostream& stream, const Subject& subject)
{
	stream<<subject._name<<" "<<subject._markscount<<std::endl;;
	for (int i = 0; i < subject._markscount; ++i)
	{
	 stream<<subject._marks[i];
	}
	return stream;
}