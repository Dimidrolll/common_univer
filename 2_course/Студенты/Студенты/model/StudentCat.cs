using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Студенты.model
{
    public class StudentCat : Student
    {
        [RusName("Еда")]
        public string Food { get; set; }

        public StudentCat() : base()
        {
            Food = "";
        }
    }
}
