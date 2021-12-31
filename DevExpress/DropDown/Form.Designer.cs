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
            this.ComboStatic,this.ComboDB});
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
            // Combo - default values
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
            this.ComboDB.VisibleIndex = 2;
            this.ComboDB.Width = 81;
            // 
            // Form
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(722, 422);
            this.Controls.Add(this.gridControl1);
            this.Controls.Add(this.textEdit1);
            this.Name = "Form";
            this.Text = "Form";
            ((System.ComponentModel.ISupportInitialize)(this.textEdit1.Properties)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridControl1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.gridView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private DevExpress.XtraEditors.TextEdit textEdit1;
        private DevExpress.XtraGrid.GridControl gridControl1;
        private DevExpress.XtraGrid.Views.Grid.GridView gridView1;
        private DevExpress.XtraGrid.Columns.GridColumn Param;
        private DevExpress.XtraGrid.Columns.GridColumn Mark;
        private DevExpress.XtraGrid.Columns.GridColumn ComboStatic;
        private DevExpress.XtraGrid.Columns.GridColumn ComboDB;
    }
}