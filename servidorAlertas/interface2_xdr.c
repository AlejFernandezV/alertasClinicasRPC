/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "interface2.h"

bool_t
xdr_paciente_SA_SN (XDR *xdrs, paciente_SA_SN *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->numeroHabitacion))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->nombre, MAXNOM,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->apellido, MAXAPEL,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->edad))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_indicadores_SA_SN (XDR *xdrs, indicadores_SA_SN *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, (3 + ( 2 )) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->frecuencia_cardiaca))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->tension_arterial, 2,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->frecuencia_respiratoria))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->saturacion_oxigeno))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->frecuencia_cardiaca);
		{
			register int *genp;

			for (i = 0, genp = objp->tension_arterial;
				i < 2; ++i) {
				IXDR_PUT_LONG(buf, *genp++);
			}
		}
		IXDR_PUT_LONG(buf, objp->frecuencia_respiratoria);
		IXDR_PUT_LONG(buf, objp->saturacion_oxigeno);
		}
		 if (!xdr_float (xdrs, &objp->temperatura))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, (3 + ( 2 )) * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->frecuencia_cardiaca))
				 return FALSE;
			 if (!xdr_vector (xdrs, (char *)objp->tension_arterial, 2,
				sizeof (int), (xdrproc_t) xdr_int))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->frecuencia_respiratoria))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->saturacion_oxigeno))
				 return FALSE;

		} else {
		objp->frecuencia_cardiaca = IXDR_GET_LONG(buf);
		{
			register int *genp;

			for (i = 0, genp = objp->tension_arterial;
				i < 2; ++i) {
				*genp++ = IXDR_GET_LONG(buf);
			}
		}
		objp->frecuencia_respiratoria = IXDR_GET_LONG(buf);
		objp->saturacion_oxigeno = IXDR_GET_LONG(buf);
		}
		 if (!xdr_float (xdrs, &objp->temperatura))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->frecuencia_cardiaca))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->tension_arterial, 2,
		sizeof (int), (xdrproc_t) xdr_int))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->frecuencia_respiratoria))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->saturacion_oxigeno))
		 return FALSE;
	 if (!xdr_float (xdrs, &objp->temperatura))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_alerta (XDR *xdrs, alerta *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->horaAlerta, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->fechaAlerta, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->puntuacion))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_notificacion (XDR *xdrs, notificacion *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_vector (xdrs, (char *)objp->horaAlerta, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->fechaAlerta, 50,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->vecUltimasAlertas, 5,
		sizeof (alerta), (xdrproc_t) xdr_alerta))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->cantidadAlertas))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->puntuacion))
		 return FALSE;
	 if (!xdr_indicadores_SA_SN (xdrs, &objp->objIndicadores))
		 return FALSE;
	 if (!xdr_paciente_SA_SN (xdrs, &objp->objPaciente))
		 return FALSE;
	return TRUE;
}