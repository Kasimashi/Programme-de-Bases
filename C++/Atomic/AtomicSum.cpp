#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <thread>
#include <atomic>

#define USE_ATOMIC
#ifdef USE_ATOMIC
std::atomic<long> multiThreadedSum(0) ;
#else
#warning "Atomic not used"
long multiThreadedSum = 0;
#endif



void SumNumbers(const std::vector<int>& toBeSummed, int idxStart, int idxEnd ) 
{

    for (int i = idxStart; i <= idxEnd; ++i)
    {
        multiThreadedSum+= toBeSummed[i];
    }
}

int main( int, char**)
{
    std::vector<int> toBeSummed;
    
    for (int i=0; i < 30000; ++i)
    {
        toBeSummed.push_back( rand() );
    }
    
    long sum = 0;
    
    for (int i=0; i < toBeSummed.size(); ++i)
    {
        sum += toBeSummed[i];
    }
    
    printf( "The sum was %d\n", sum);
    
    std::thread t1(SumNumbers, toBeSummed, 0, 9999);
    std::thread t2(SumNumbers, toBeSummed, 10000, 19999);
    std::thread t3(SumNumbers, toBeSummed , 20000, 29999);
    
    t1.join();
    t2.join();
    t3.join();
    
#ifdef USE_ATOMIC
    printf( "The sum was %d\n", multiThreadedSum.load());
#else
    printf( "The sum was %d\n", multiThreadedSum);
#endif
    
    return 0;
}
