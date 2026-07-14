package main

// Addition is a Concrete Element — addition of two sub-expressions.
type Addition struct {
	left  Expression
	right Expression
}

func NewAddition(left, right Expression) *Addition {
	return &Addition{left: left, right: right}
}

func (a *Addition) Left() Expression  { return a.left }
func (a *Addition) Right() Expression { return a.right }

func (a *Addition) Accept(visitor Visitor) {
	visitor.VisitAddition(a)
}
