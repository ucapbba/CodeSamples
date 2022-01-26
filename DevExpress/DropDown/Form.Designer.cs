namespace DropDown
{
    partial class Form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textEdit1 = new DevExpress.XtraEditors.TextEdit();
            this.gridControl1 = new DevExpress.XtraGrid.GridControl();
            this.gridView1 = new DevExpress.XtraGrid.Views.Grid.GridView();
            this.Param = new DevExpress.XtraGrid.Columns.GridColumn();
            this.Mark = new DevExpress.XtraGrid.Columns.GridColumn();
            this.ComboStatic = new DevExpress.XtraGrid.Columns.GridColumn();
            this.ComboDB = new DevExpress.XtraGrid.Columns.GridColumn();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.textEdit1.Properties)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridControl1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // textEdit1
            // 
            this.textEdit1.Location = new System.Drawing.Point(25, 28);
            this.textEdit1.Name = "textEdit1";
            this.textEdit1.Size = new System.Drawing.Size(100, 20);
            this.textEdit1.TabIndex = 0;
            // 
            // gridControl1
            // 
            this.gridControl1.Location = new System.Drawing.Point(56, 119);
            this.gridControl1.MainView = this.gridView1;
            this.gridControl1.Name = "gridControl1";
            this.gridControl1.Size = new System.Drawing.Size(400, 200);
            this.gridControl1.TabIndex = 1;
            this.gridControl1.ViewCollection.AddRange(new DevExpress.XtraGrid.Views.Base.BaseView[] {
            this.gridView1});
            // 
            // gridView1
            // 
            this.gridView1.Columns.AddRange(new DevExpress.XtraGrid.Columns.GridColumn[] {
            this.Param,
            this.Mark,
            this.ComboStatic,
            this.ComboDB});
            this.gridView1.GridControl = this.gridControl1;
            this.gridView1.Name = "gridView1";
            this.gridView1.OptionsBehavior.AllowAddRows = DevExpress.Utils.DefaultBoolean.True;
            this.gridView1.OptionsBehavior.AllowDeleteRows = DevExpress.Utils.DefaultBoolean.True;
            // 
            // Param
            // 
            this.Param.FieldName = "Param";
            this.Param.MinWidth = 21;
            this.Param.Name = "Param";
            this.Param.OptionsEditForm.UseEditorColRowSpan = false;
            this.Param.Visible = true;
            this.Param.VisibleIndex = 0;
            this.Param.Width = 81;
            // 
            // Mark
            // 
            this.Mark.FieldName = "Mark";
            this.Mark.MinWidth = 21;
            this.Mark.Name = "Mark";
            this.Mark.OptionsEditForm.UseEditorColRowSpan = false;
            this.Mark.Visible = true;
            this.Mark.VisibleIndex = 1;
            this.Mark.Width = 81;
            // 
            // ComboStatic
            // 
            this.ComboStatic.FieldName = "ComboStatic";
            this.ComboStatic.MinWidth = 21;
            this.ComboStatic.Name = "ComboStatic";
            this.ComboStatic.OptionsEditForm.UseEditorColRowSpan = false;
            this.ComboStatic.Visible = true;
            this.ComboStatic.VisibleIndex = 2;
            this.ComboStatic.Width = 81;
            // 
            // ComboDB
            // 
            this.ComboDB.FieldName = "ComboDB";
            this.ComboDB.MinWidth = 21;
            this.ComboDB.Name = "ComboDB";
            this.ComboDB.OptionsEditForm.UseEditorColRowSpan = false;
            this.ComboDB.Visible = true;
            this.ComboDB.VisibleIndex = 3;
            this.ComboDB.Width = 81;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(239, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(89, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Date of last run :";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(345, 31);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(63, 13);
            this.label2.TabIndex = 3;
            this.label2.Text = "26/12/2022";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(242, 1);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(144, 27);
            this.button1.TabIndex = 4;
            this.button1.Text = "Update Date";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(722, 422);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.gridControl1);
            this.Controls.Add(this.textEdit1);
            this.Name = "Form";
            this.Text = "Form";
            ((System.ComponentModel.ISupportInitialize)(this.textEdit1.Properties)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridControl1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private DevExpress.XtraEditors.TextEdit textEdit1;
        private DevExpress.XtraGrid.GridControl gridControl1;
        private DevExpress.XtraGrid.Views.Grid.GridView gridView1;
        private DevExpress.XtraGrid.Columns.GridColumn Param;
        private DevExpress.XtraGrid.Columns.GridColumn Mark;
        private DevExpress.XtraGrid.Columns.GridColumn ComboStatic;
        private DevExpress.XtraGrid.Columns.GridColumn ComboDB;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button1;
    }
}