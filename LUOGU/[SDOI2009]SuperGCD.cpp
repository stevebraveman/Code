#include <cstdio>
#include <iostream>
class BigInt {
		//Input
		friend istream& operator>>(istream&, BigInt&);
		//Output
		friend ostream& operator<<(ostream&, const BigInt&);
		friend bool operator==(const BigInt&, const BigInt&);
		friend bool operator<(const BigInt&, const BigInt&);
		friend bool operator>(const BigInt&, const BigInt&);
	public:
		BigInt();
		BigInt(const string&);
		BigInt(const BigInt&);
		BigInt(int);
		BigInt(const char*);
		BigInt& operator=(const BigInt&);
		BigInt& operator+=(const BigInt&);
		BigInt& operator-=(const BigInt&);
		BigInt& operator*=(const BigInt&);
		BigInt& operator/=(const BigInt&);
		BigInt& operator%=(const BigInt&);
		//prefix increment
		BigInt& operator++();
		//prefix decrement
		BigInt& operator--();
		//postfix increment
		BigInt operator++(int);
		//postfix decrement
		BigInt operator--(int);
	private:
		//unsigned +=
		void plus(const string&);
		//unsigned -=
		void minus(const string&);
		//unsigned ==
		bool equal(const string&) const;
		//unsigned <
		bool smaller(const string&) const;
		//unsigned >
		bool greater(const string&) const;
		string num;
};
inline BigInt::BigInt() : num("+0") {}
inline BigInt::BigInt(const string& strnum) : num(strnum) {
	if(num.size() > 0) {
		if(num[0] != '-' && num[0] != '+') {
			string::size_type i = 0;
			for(; i < num.size() - 1 && num[i] == '0'; ++i);
			if(i > 0)
				num.replace(0, i, "+");
			else
				num.insert(0, 1, '+');
		} else {
			if(num.size() == 1)
				num = "+0";
			else {
				string::size_type i = 1;
				for(; i < num.size() - 1 && num[i] == '0'; ++i);
				if(i > 1)
					num.erase(1, i-1);
				if(num == "-0")
					num[0] = '+';
			}
		}
	} else
		num = "+0";
}

inline BigInt::BigInt(const BigInt& val) : num(val.num) {}
inline BigInt::BigInt(int n) {
	if(n >= 0)
		num = '+';
	else {
		num = '-';
		n *= -1;
	}
	string temp;
	while(n) {
		temp += n % 10 + '0';
		n /= 10;
	}
	for(int i = temp.size() - 1; i >= 0; --i)
		num += temp[i];
}

inline BigInt::BigInt(const char* str) : num(str) {
	if(num.size() > 0) {
		if(num[0] != '-' && num[0] != '+') {
			string::size_type i = 0;
			for(; i < num.size() - 1 && num[i] == '0'; ++i);
			if(i > 0)
				num.replace(0, i, "+");
			else
				num.insert(0, 1, '+');
		} else {
			if(num.size() == 1)
				num = "+0";
			else {
				string::size_type i = 1;
				for(; i < num.size() - 1 && num[i] == '0'; ++i);
				if(i > 1)
					num.erase(1, i-1);
				if(num == "-0")
					num[0] = '+';
			}
		}
	} else
		num = "+0";
}

istream& operator>>(istream& in, BigInt& val) {
	in >> val.num;
	if(1) { //原来里面是in？？总之这样能用了。。。
		if(val.num[0] != '-' && val.num[0] != '+') {
			string::size_type i = 0;
			for(; i < val.num.size() - 1 && val.num[i] == '0'; ++i);
			if(i > 0)
				val.num.replace(0, i, "+");
			else
				val.num.insert(0, 1, '+');
		} else {
			if(val.num.size() == 1)
				val.num = "+0";
			else {
				string::size_type i = 1;
				for(; i < val.num.size() - 1 && val.num[i] == '0'; ++i);
				if(i > 1)
					val.num.erase(1, i-1);
				if(val.num == "-0")
					val.num[0] = '+';
			}
		}
	} else
		val = BigInt();
	return in;
}

ostream& operator<<(ostream& os, const BigInt& val) {
	if(val.num[0] == '-')
		os << val.num;
	else
		os << val.num.substr(1);
	return os;
}
inline bool BigInt::equal(const string& rval) const {
	return num.substr(1) == rval.substr(1);
}
inline bool BigInt::smaller(const string& rval) const {
	if(num.size() == rval.size()) {
		return num.substr(1) < rval.substr(1);
	} else
		return num.size() < rval.size();
}
inline bool BigInt::greater(const string& rval) const {
	if(num.size() == rval.size()) {
		return num.substr(1) > rval.substr(1);
	} else
		return num.size() > rval.size();
}
inline bool operator==(const BigInt& lval, const BigInt& rval) {
	return lval.num == rval.num;
}

inline bool operator!=(const BigInt& lval, const BigInt& rval) {
	return !(lval == rval);
}

inline bool operator<(const BigInt& lval, const BigInt& rval) {
	if(lval.num[0] != rval.num[0])
		return lval.num[0] > rval.num[0];
	else {
		if(lval.num[0] == '+')
			return lval.smaller(rval.num);
		else
			return rval.smaller(lval.num);
	}
}

inline bool operator>(const BigInt& lval, const BigInt& rval) {
	if(lval.num[0] != rval.num[0])
		return lval.num[0] < rval.num[0];
	else {
		if(lval.num[0] == '+')
			return lval.greater(rval.num);
		else
			return rval.greater(lval.num);
	}
}

inline bool operator<=(const BigInt& lval, const BigInt& rval) {
	return !(lval > rval);
}

inline bool operator>=(const BigInt& lval, const BigInt& rval) {
	return !(lval < rval);
}

inline BigInt& BigInt::operator =(const BigInt &rval) {
	num = rval.num;
	return *this;
}
//unsigned +=
void BigInt::plus(const string& rval) {
	if(num.size() < rval.size())
		num.insert(1, rval.size() - num.size(), '0');
	string::size_type i = num.size() - 1;
	string::size_type j = rval.size() - 1;
	while(j > 1) {
		num[i] += rval[j--] - '0';
		if(num[i] > '9') {
			num[i] -= 10;
			++num[i-1];
		}
		--i;
	}
	num[i] += rval[1] - '0';
	while(i > 1 && num[i] > '9') {
		num[i] -= 10;
		++num[--i];
	}
	if(num[1] > '9') {
		num[1] -= 10;
		num.insert(1, 1, '1');
	}
}

//unsigned -=
void BigInt::minus(const string& rval) {
	string::size_type i = num.size() - 1;
	for(string::size_type j = rval.size() - 1; j > 0; --j, --i) {
		num[i] -= rval[j] - '0';
		if(num[i] < '0') {
			num[i] += 10;
			--num[i-1];
		}
	}
	while(i > 1 && num[i] < '0') {
		num[i] += 10;
		--num[--i];
	}
	i = 1;
	for(; i < num.size() - 1 && num[i] == '0'; ++i);
	if(i > 1)
		num.erase(1, i-1);
}
BigInt& BigInt::operator +=(const BigInt &rval) {
	if(num[0] == rval.num[0])
		plus(rval.num);
	else {
		if(equal(rval.num)) {
			num = "+0";
		} else if(smaller(rval.num)) {
			string temp = num;
			num = rval.num;
			minus(temp);
		} else
			minus(rval.num);
	}
	return *this;
}

BigInt& BigInt::operator -=(const BigInt &rval) {
	if(num[0] == rval.num[0]) {
		if(equal(rval.num)) {
			num = "+0";
		} else if(smaller(rval.num)) {
			string temp = num;
			num = rval.num;
			minus(temp);
			if(num[0] == '+')
				num[0] = '-';
			else
				num[0] = '+';
		} else
			minus(rval.num);
	} else {
		plus(rval.num);
	}
	return *this;
}
BigInt operator+(const BigInt& lval, const BigInt& rval) {
	BigInt sum(lval);
	sum += rval;
	return sum;
}

BigInt operator-(const BigInt& lval, const BigInt& rval) {
	BigInt diff(lval);
	diff -= rval;
	return diff;
}
//prefix increment
BigInt& BigInt::operator ++() {
	string::size_type i = num.size() - 1;
	if(num[0] == '+') {
		++num[i];
		while(i > 1 && num[i] > '9') {
			num[i] -= 10;
			++num[--i];
		}
		if(num[1] > '9') {
			num[1] -= 10;
			num.insert(1, 1, '1');
		}
	} else {
		--num[i];
		while(i > 1 && num[i] < '0') {
			num[i] += 10;
			--num[--i];
		}
		i = 1;
		for(; i < num.size() - 1 && num[i] == '0'; ++i);
		if(i > 1)
			num.erase(1, i-1);
		if(num[1] == '0')
			num[0] = '+';
	}
	return *this;
}
BigInt& BigInt::operator --() {
	string::size_type i = num.size() - 1;
	if(num[0] == '+') {
		if(num[1] == '0')
			num = "-1";
		else {
			--num[i];
			while(i > 1 && num[i] < '0') {
				num[i] += 10;
				--num[--i];
			}
			i = 1;
			for(; i < num.size() - 1 && num[i] == '0'; ++i);
			if(i > 1)
				num.erase(1, i-1);
		}
	} else {
		++num[i];
		while(i > 1 && num[i] > '9') {
			num[i] -= 10;
			++num[--i];
		}
		if(num[1] > '9') {
			num[1] -= 10;
			num.insert(1, 1, '1');
		}
	}
	return *this;
}
//postfix increment
BigInt BigInt::operator ++(int) {
	BigInt temp(*this);
	++*this;
	return temp;
}
//postfix decrement
BigInt BigInt::operator --(int) {
	BigInt temp(*this);
	--*this;
	return temp;
}
BigInt& BigInt::operator *=(const BigInt &rval) {
	if(num[1] == '0' || rval.num[1] == '0') {
		num = "+0";
		return *this;
	}
	vector<unsigned int> prod(num.size() + rval.num.size() - 1, 0);
	for(string::size_type i = num.size() - 1; i > 0; --i)
		num[i] -= '0';
	for(string::size_type j = rval.num.size() - 1; j > 0; --j) {
		if(rval.num[j] > '0') {
			for(string::size_type i = num.size() - 1; i > 0; --i)
				prod[i+j] += num[i] * (rval.num[j] - '0');
		}
	}
	if(num[0] == rval.num[0])
		prod[0] = '+';
	else
		prod[0] = '-';
	num = string(prod.size(), '0');
	num[0] = prod[0];
	for(vector<unsigned int>::size_type i = prod.size() - 1; i > 1; --i) {
		prod[i-1] += prod[i] / 10;
		prod[i] %= 10;
		num[i] += prod[i];
	}
	if(prod[1] == 0)
		num.erase(1, 1);
	else
		num[1] += prod[1];
	return *this;
}

BigInt& BigInt::operator /=(const BigInt &rval) {
	if(rval.num == "+0") {
		num = "*Error";
		return *this;
	}
	if(rval.smaller(num)) {
		string ans(num.size(), '0');
		if(num[0] == rval.num[0])
			ans[0] = '+';
		else
			ans[0] = '-';
		string::size_type start = 1, end = rval.num.size() - 1;
		while(end < num.size()) {
			while(!rval.greater(num.substr(start-1, end-start+2))) {
				string::size_type j = end;
				for(string::size_type i = rval.num.size() - 1; i > 0; --i, --j) {
					num[j] -= rval.num[i] - '0';
					if(num[j] < '0') {
						num[j] += 10;
						--num[j-1];
					}
				}
				while(j >= start && num[j] < '0') {
					num[j] += 10;
					--num[--j];
				}
				++ans[end];
				while(start <= end && num[start] == '0')
					++start;
			}
			while(start < num.size() && num[start] == '0')
				++start;
			if(start + rval.num.size() - 2 > end)
				end = start + rval.num.size() - 2;
			else
				++end;
		}
		start = 1;
		for(; start < ans.size() - 1 && ans[start] == '0'; ++start);
		if(start > 1)
			ans.erase(1, start-1);
		num = ans;
	} else if(rval.equal(num)) {
		string ans = "-1";
		if(num[0] == rval.num[0])
			ans[0] = '+';
		num = ans;
	} else
		num = "+0";
	return *this;
}

BigInt& BigInt::operator%=(const BigInt &rval) {
	if(rval.num == "+0") {
		num = "*Error";
		return *this;
	}
	if(rval.smaller(num)) {
		string::size_type start = 1, end = rval.num.size() - 1;
		while(end < num.size()) {
			while(!rval.greater(num.substr(start-1, end-start+2))) {
				string::size_type j = end;
				for(string::size_type i = rval.num.size() - 1; i > 0; --i, --j) {
					num[j] -= rval.num[i] - '0';
					if(num[j] < '0') {
						num[j] += 10;
						--num[j-1];
					}
				}
				while(j >= start && num[j] < '0') {
					num[j] += 10;
					--num[--j];
				}
				while(start <= end && num[start] == '0')
					++start;
			}
			while(start < num.size() && num[start] == '0')
				++start;
			if(start + rval.num.size() - 2 > end)
				end = start + rval.num.size() - 2;
			else
				++end;
		}
		start = 1;
		for(; start < num.size() - 1 && num[start] == '0'; ++start);
		if(start > 1)
			num.erase(1, start-1);
		if(num == "-0")
			num[0] = '+';
	} else if(rval.equal(num)) {
		num = "+0";
	}
	return *this;
}
BigInt operator*(const BigInt& lval, const BigInt& rval) {
	BigInt product(lval);
	product *= rval;
	return product;
}

BigInt operator/(const BigInt& lval, const BigInt& rval) {
	BigInt quotient(lval);
	quotient /= rval;
	return quotient;
}

BigInt operator%(const BigInt& lval, const BigInt& rval) {
	BigInt mod(lval);
	mod %= rval;
	return mod;
}
BigInt gcd(BigInt a , BigInt b) {
	if (b == "0") return a;
	else return gcd(b , a % b);
}
int main() {
	BigInt a , b;
	std::cin >> a >> b;
	std::cout << gcd(a , b);
}
