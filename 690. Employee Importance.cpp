
690. Employee Importance

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        stack<int> sub;
        int ret = 0;
        for(int i = 0;i<employees.size();++i)
        {
            if(employees[i]->id==id){
                for(int val:employees[i]->subordinates)
                    sub.push(val);
                ret += employees[i]->importance;
            }
        }

        while(!sub.empty())
        {
            int i = sub.top();
            sub.pop();
            for(int j = 0;j<employees.size();++j)
            {
                if(employees[j]->id==i){
                    ret += employees[j]->importance;
                    for(int val:employees[j]->subordinates)
                    {
                        sub.push(val);
                    }
                }
            }
        }
        return ret;
    }
};