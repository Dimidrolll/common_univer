using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Студенты.model
{
    [AttributeUsage(AttributeTargets.Property)]
    public class RusName : Attribute
    {
        private readonly string _rusName;

        public RusName(string rusName)
        {
            _rusName = rusName;
        }

        public string GetRusName()
        {
            return _rusName;
        }
    }
}
