using System;
using System.Xml.Serialization;

namespace Студенты.model
{
    [Serializable]
    [XmlInclude(typeof(StudentCat))]
    public class Student
    {
        [RusName("Фамилия")]
        public string Surname { get; set; }
        [RusName("Имя")]
        public string Name { get; set; }
        [RusName("Факультет")]
        public string Faculty { get; set; }

        public Student()
        {
            Surname = "";
            Name = "";
            Faculty = "";
        }

    }

    
}
