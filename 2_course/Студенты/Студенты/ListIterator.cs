using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Студенты.model;

namespace Студенты
{
     public class ListIterator
    {
        private List<Student> list;
        private int _index = -1;

        public ListIterator(List<Student> list)
        {
            this.list = list;
        }

        public Student Current
        {
            get { return list[_index]; }
        }

        public bool HasNext()
        {
            return _index < this.list.Count - 1;
        }

        public bool HasPrevious()
        {
            return _index > 0;
        }

        public Student Next()
        {
            if (!HasNext())
            {
                throw new IndexOutOfRangeException("Next elem not found");
            }
            return list[++_index];
        }

        public Student Previous()
        {
            if (!HasPrevious())
            {
                throw new IndexOutOfRangeException("Prev elem not found");
            }
            return list[--_index];
        }

        public void Add(Student student)
        {
            list.Add(student);
            if (_index < 0)
            {
                _index++;
            }
        }

        public void Remove()
        {
            list.RemoveAt(_index);
            if (_index > 0)
            {
                --_index;
            }
        }

        public ListIterator Copy()
        {
            return new ListIterator(list);
        }

        public bool IsEmpty()
        {
            return list.Count == 0;
        }
    }
}
