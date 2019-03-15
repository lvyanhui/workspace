#include <iostream>
using namespace std;
class Work;

//状态
class State
{
	public:  
		virtual void Operation(Work *work) {}
};

//排气状态
class ExhaustState: public State  
{  
	public:  
		void Operation(Work *work)  //排气操作
		{  
			if(work->GetStep() == 4)  
			{
				cout<<"Step : "<<work->GetStep()<<"排气操作"<<endl;  
			}
		}
};

//做功状态
class ActState: public State
{
	public:
		void Operation(Work *work) //做功操作
		{
			if(work->GetStep() == 3)
			{
				cout<<"Step : "<<work->GetStep()<<"做功操作"<<endl;  
			}
			else
			{
				work->SetState(new ExhaustState());
				work->Operation();
			}
		}
};  

//压缩状态
class CompressState: public State  
{
	public:
		void Operation(Work *work) //压缩操作
		{
			if(work->GetStep() == 2)
			{
				cout<<"Step : "<<work->GetStep()<<"压缩操作"<<endl;  
			}
			else
			{
				work->SetState(new ActState());  
				work->Operation();  
			}  
		}
};

//吸气状态
class InhaleState: public State
{
	public:  
		void Operation(Work *work) //吸气操作
		{
			if(work->GetStep() == 1)
			{
				cout<<"Step : "<<work->GetStep()<<"吸气操作"<<endl;
			}
			else
			{
				State *p = new CompressState();
				work->SetState(p);
				work->Operation();
			}
		}
};

//工作
class Work
{
	private:
		State *m_state;  //目前状态
		int m_step;      //步骤

	public:  
		Work(State *state): m_state(state), m_step(0)
	{}

		~Work()
		{
			delete m_state;
		}

		int GetStep()
		{
			return m_step;
		}

		void SetStep(int step)
		{
			m_step = step;
		}

		void SetState(State *state)
		{
			delete m_state;
			m_state = state;
		}

		void Operation()
		{
			m_state->Operation(this);
		}
};



//测试代码
int main()  
{
	State* st = new InhaleState(); //初始状态

	Work *work = new Work(st);

	for(int i = 1; i < 5; ++i)
	{
		work->SetStep(i);

		work->Operation(); //操作
	}

	delete work;

	return 0;
}
