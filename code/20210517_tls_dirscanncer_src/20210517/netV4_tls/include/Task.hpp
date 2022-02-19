 ///
 /// @file    Task.hpp
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2021-05-07 16:32:37
 ///
 
#ifndef __WD_TASK_H__
#define __WD_TASK_H__
#include <functional>

namespace wd
{
using Task = std::function<void()>;
}//end of namespace wd


#endif
