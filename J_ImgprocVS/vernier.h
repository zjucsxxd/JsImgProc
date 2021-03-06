/*  vernier  */
/* �α� */
#pragma once

/* singleton */
class Vernier
{
private:
	static Vernier *_singleton;
	int *_v;
	int _capacity;
	/* point to current index */
	int _pointer;
	/* user specific length */
	int _length;

	Vernier(Vernier&);
	Vernier & operator = (Vernier&);

	Vernier()
	{
		_capacity = 255;
		_v = new int[_capacity];
		//point to nothing
		_pointer = -1;
		_length = 0;
	}
	~Vernier()
	{
		delete _v;
	}

public:
	static Vernier *getInstance()
	{
		if (_singleton == nullptr)
		{
			_singleton = new Vernier();
		}
		return _singleton;
	}

	/* user specify length */
	void setLength(int l)
	{
		_length = l;
	}
	int getLength()
	{
		return _length;
	}

	bool init(int length)
	{
		setLength(length);

		if (_length > _capacity || _length <= 0)
		{
			return false;
		}

		for (int i = 0; i < _length; i++)
		{
			_v[i] = i;
		}

		/* set vernier to the tail of vector */
		_pointer = _length - 1;
		
		return true;
	}

	void increase()
	{
		/* '_pointer > -1' to make sure Vienier is correctly initialized */
		if (_pointer > -1 && _pointer < _length)
		{
			_pointer ++;
		}
	}

	void decrease()
	{
		if (_pointer > 0)
		{
			_pointer --;
		}
	}

	int getCurrentIdx()
	{
		return _pointer;
	}
};