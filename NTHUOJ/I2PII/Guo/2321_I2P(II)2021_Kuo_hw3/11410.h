#ifndef FUNCTION_H
#define FUNCTION_H
#include<cstddef>
#include<iosfwd>

namespace oj
{
	class Memory_leak_count	//check whether the process has memory leak
	{
		friend void memory_leak_count_check();
		static unsigned count_;
	public:
		Memory_leak_count();
		~Memory_leak_count();
	};

	struct Int	//you can treat Int as int
	{
		int val;	//store int in val, you this val
		Int();
		Int(int val);
		Int(const Int &);	//copy constructor
		operator int&()	//treat Int as int, conversion function
		{
			return val;
		}
		operator int() const	//treat Int as int, conversion function
		{
			return val;
		}
		Int& operator=(const Int &);	//copy constructor
	private:
		Memory_leak_count count_;	//you don't have to pay attention on this
	};

	typedef Int data_t;

	class Vector
	{
	public:
		typedef std::size_t size_type;
		typedef Int value_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
	private:
		pointer begin_;	//begin of array
		pointer end_;	//end of array
		pointer last_;	//end of current element
	public:
		Vector();
		
		size_type capacity() const;
		size_type size() const;
		
		//ignore the keyword "inline"
		//operator[] makes Vector like a C-array, for example
		//int a[2]{2,1};
		//Vector vec;
		//vec.push_back(1);
		//vec.push_back(2);
		//vec[0] is equal to a[1]
		//vec[1] is equal to a[0]
		inline reference operator[](const size_type pos)
		{
			return begin_[pos];
		}
		inline const_reference operator[](const size_type pos) const
		{
			return begin_[pos];
		}
		
		void pop_back();
		void push_back(value_type val);
		void insert(size_type pos,size_type count,value_type val);
		
		void reserve(size_type new_capacity);
		void resize(size_type new_size);
		
		~Vector();
	};

	std::ostream& operator<<(std::ostream &os,const Vector &vec);	//for cout

	void memory_leak_count_check();	//you don't have to pay attention on this


}

namespace oj{
	Vector::Vector(){
		begin_ = new Int[0];
		last_ = end_ = begin_;
	}
	Vector::size_type Vector::capacity() const{ 
		return end_ - begin_;
	}
	Vector::size_type Vector::size() const{
		return last_ - begin_;
	}
	void Vector::pop_back(){
		if(size() > 0) last_--;
	}
	void Vector::push_back(value_type val){
		if(capacity() == 0) reserve(1);
		else if(size() == capacity()) reserve(capacity()*3);
		(*last_) = val;
		last_++;
		return;
	}
	void Vector::insert(size_type pos,size_type count,value_type val){
		if(count + size() > capacity())
			reserve(capacity() + (capacity()/2 > count ? capacity()/2 : count));
		resize(size() + count);
		for(size_type i = pos + count; i < size(); i++){
			begin_[i] = begin_[i - count];
		}
		for(size_type i = pos; i < pos + count; i++){
			begin_[i] = val;
		}
	}
	// Capacity 0 1 3 9 
	void Vector::reserve(size_type new_capacity){
		if(new_capacity <= capacity()) return;
		// else
		size_type sz = size();
		pointer new_begin_ = new value_type[new_capacity];
		for(size_type i = 0; i < sz; i++){
			new_begin_[i] = begin_[i];
		}
		delete [] begin_;
		begin_ = new_begin_;
		last_ = begin_ + sz;
		end_ = begin_ + new_capacity;
		return;
	}
	void Vector::resize(size_type new_size){
		if(new_size < 0) return;
		if(new_size <= size()){
			last_ = begin_ + new_size;
		}
		else{
			reserve(new_size);
			size_type i = size();
			for(; i < new_size; i++){
				begin_[i] = 0;
			}
			last_ = begin_+i;
		}
		return;
	}
	Vector::~Vector(){
		delete [] begin_;
	}
}

#endif