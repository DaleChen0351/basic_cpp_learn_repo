#ifndef _SMART_PTRS_H_
#define _SMART_PTRS_H_
namespace myPoint
{
class Object
{
public:
	Object(int id) :m_id(id) { std::cout << "id = "<<m_id<<std::endl; }
	~Object() { std::cout << "bye bye " << m_id << std::endl; }
	int GetID() const { return m_id; }

private:
	int m_id;
};


typedef std::shared_ptr<Object> ObjectPtr;



}

#endif // !_SMART_PTRS_H_



