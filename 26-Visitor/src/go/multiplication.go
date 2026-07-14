package main

// Multiplication is a Concrete Element — multiplication of two sub-expressions.
type Multiplication struct {
	left  Expression
	right Expression
}

func NewMultiplication(left, right Expression) *Multiplication {
	return &Multiplication{left: left, right: right}
}

func (m *Multiplication) Left() Expression  { return m.left }
func (m *Multiplication) Right() Expression { return m.right }

func (m *Multiplication) Accept(visitor Visitor) {
	visitor.VisitMultiplication(m)
}
