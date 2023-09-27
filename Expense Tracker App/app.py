from flask import Flask, render_template, request, redirect, url_for
import sqlite3
import datetime

app = Flask(__name__)

# Database setup
conn = sqlite3.connect('expenses.db')
cursor = conn.cursor()

# Create 'expenses' table if it doesn't exist
cursor.execute('''
    CREATE TABLE IF NOT EXISTS expenses (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        date TEXT,
        description TEXT,
        amount REAL
    )
''')
conn.commit()

# Routes

@app.route('/')
def index():
    # Fetch expenses from the database and render them in the template
    cursor.execute('SELECT * FROM expenses')
    expenses = cursor.fetchall()
    return render_template('index.html', expenses=expenses)

@app.route('/add', methods=['POST'])
def add_expense():
    if request.method == 'POST':
        date = request.form['date']
        description = request.form['description']
        amount = request.form['amount']
        
        # Validate date format
        try:
            datetime.datetime.strptime(date, '%Y-%m-%d')
        except ValueError:
            return "Invalid date format. Please use YYYY-MM-DD."

        # Validate amount is a number
        try:
            amount = float(amount)
        except ValueError:
            return "Amount must be a valid number."
        
        # Insert the new expense into the database
        cursor.execute("INSERT INTO expenses (date, description, amount) VALUES (?, ?, ?)", (date, description, amount))
        conn.commit()

    return redirect(url_for('index'))

@app.route('/edit/<int:expense_id>', methods=['GET', 'POST'])
def edit_expense(expense_id):
    if request.method == 'POST':
        date = request.form['date']
        description = request.form['description']
        amount = request.form['amount']

        # Validation (same as above)
        try:
            datetime.datetime.strptime(date, '%Y-%m-%d')
        except ValueError:
            return "Invalid date format. Please use YYYY-MM-DD."

        try:
            amount = float(amount)
        except ValueError:
            return "Amount must be a valid number."
        
        # Update the expense in the database
        cursor.execute("UPDATE expenses SET date=?, description=?, amount=? WHERE id=?", (date, description, amount, expense_id))
        conn.commit()
        return redirect(url_for('index'))
    else:
        # Fetch the expense to be edited from the database
        cursor.execute('SELECT * FROM expenses WHERE id = ?', (expense_id,))
        expense = cursor.fetchone()
        return render_template('edit.html', expense=expense)

@app.route('/delete/<int:expense_id>')
def delete_expense(expense_id):
    # Delete the expense from the database by ID
    cursor.execute('DELETE FROM expenses WHERE id = ?', (expense_id,))
    conn.commit()
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
