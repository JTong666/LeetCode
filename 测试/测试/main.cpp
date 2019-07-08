#include <iostream>
#include <thread> 
#include<mutex>
template<typename Iterator, typename T>
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T& result)
	{
		result = std::accumulate(first, last, result);
	}
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
	unsigned long const length = std::distance(first, last);

	if (!length) // 1
		return init;

	unsigned long const min_per_thread = 25;
	unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread; 

	unsigned long const hardware_threads = std::thread::hardware_concurrency();            //number of thread

	unsigned long const num_threads = 
		std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

	unsigned long const block_size = length / num_threads;

	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads - 1);  

	Iterator block_start = first;
	for (unsigned long i = 0; i < (num_threads - 1); ++i)
	{
		Iterator block_end = block_start;
		std::advance(block_end, block_size); 
		threads[i] = std::thread(     
			accumulate_block<Iterator, T>()
			block_start, block_end, std::ref(results[i]));
		block_start = block_end; 
	}
	accumulate_block<Iterator, T>()(
		block_start, last, results[num_threads - 1]);
	std::for_each(threads.begin(), threads.end(),
		std::mem_fn(&std::thread::join));  

	return std::accumulate(results.begin(), results.end(), init); 

}




class some_data
{
	int a;
	std::string b;
public:
	void do_something();
};



class data_wrapper
{
private:
	some_data data;
	std::mutex m;
public:
	template<typename Function>
	void process_data(Function func)
	{
		std::lock_guard<std::mutex> l(m);
		func(data);    // 1 ���ݡ����������ݸ��û�����
	}
};


some_data* unprotected;


void malicious_function(some_data& protected_data)
{
	unprotected = &protected_data;
}

data_wrapper x;

void foo()
{
	x.process_data(malicious_function);    // 2 ����һ�����⺯��
	unprotected->do_something();    // 3 ���ޱ���������·��ʱ�������
}


