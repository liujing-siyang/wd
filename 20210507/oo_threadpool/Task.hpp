 ///
 /// @file    Task.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 16:32:37
 ///
 
#ifndef __WD_TASK_H__
#define __WD_TASK_H__

namespace wd
{

class Task
{
public:
	virtual void process() = 0;
	virtual ~Task() {}
};

}//end of namespace wd


#endif
