
#ifndef PIGGY_ROBOTOMYREQUESTFORM_HPP
#define PIGGY_ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
public:
    RobotomyRequestForm(std::string name);
    virtual ~RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    void  action() const;
};


#endif //PIGGY_ROBOTOMYREQUESTFORM_HPP
