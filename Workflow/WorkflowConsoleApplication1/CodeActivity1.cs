using System;
using System.Activities;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Workflow.ComponentModel;

namespace WorkflowConsoleApplication1
{

    public sealed class AnotherActivity : NativeActivity
    {
        // Define an activity input argument of type string
        // public InArgument<string> Text { get; set; }
        public OutArgument<string> TextOut { get; set; }
        // If your activity returns a value, derive from CodeActivity<TResult>
        // and return the value from the Execute method.
        protected override void Execute(NativeActivityContext context)
        {
            TextOut.Set(context, "Hellow"); //variable1 out
            string a = TextOut.Get(context);

            Bookmark myBookmark = context.CreateBookmark("MyBookmark", OnResumeBookmark);
            //wf is frozen
            context.ResumeBookmark(myBookmark, "my value");
           // context.CloseActivity();
        }

        private void OnResumeBookmark(NativeActivityContext context, Bookmark bookmark, object value)
        {
            Console.WriteLine("Executing bookmark with value" + value.ToString());
        }

        protected override bool CanInduceIdle
        {
            get { return true; }
        }
    }

       

 
    public sealed class CodeActivity1 : NativeActivity
    {
        // Define an activity input argument of type string
        public InArgument<string> Text { get; set; }
        public OutArgument<string> TextOut { get; set; }
        // If your activity returns a value, derive from CodeActivity<TResult>
        // and return the value from the Execute method.
        protected override void Execute(NativeActivityContext context)
        {
            // Obtain the runtime value of the Text input argument
            string text = Text.Get(context);
            Console.WriteLine(text);

            // Do any necessary processing here
            XtraForm1 form = new XtraForm1(text);
            if (form.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                string inputValue = form.InputValue;
                TextOut.Set(context, inputValue);
            }
        }

        protected override bool CanInduceIdle
        {
            get { return true; }
        }
    }


    public sealed class CodeActivity2 : NativeActivity
    {
        // Define an activity input argument of type string
        public InArgument<string> myTextCache { get; set; }
        //protected override void CacheMetadata(NativeActivityMetadata metadata) //not sure what the point of this is
        //{
        //    var arg1 = new RuntimeArgument("TextCache", typeof(string), ArgumentDirection.In);
        //    metadata.AddArgument(arg1);
        //    // Bind input and output arguments to expressions and variables in the workflow
        //    metadata.Bind(this.myTextCache, arg1);
        //}
        // If your activity returns a value, derive from CodeActivity<TResult>
        // and return the value from the Execute method.
        protected override void Execute(NativeActivityContext context)
        {
            string text = myTextCache.Get(context);
            // Obtain the runtime value of the Text input argument
            // string text = context.GetValue(this.Text);
        }
    }
}
