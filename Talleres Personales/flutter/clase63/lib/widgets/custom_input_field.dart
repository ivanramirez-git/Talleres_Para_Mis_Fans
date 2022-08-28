import 'package:flutter/material.dart';

class CustonInputField extends StatelessWidget {
  final String? hintText;
  final String? labelText;
  final String? helperText;
  final IconData? icon;
  final IconData? suffixIcon;
  final int? minCharacters;
  final int? maxCharacters;
  final bool? autofocus;
  final bool? isPassword;
  final String? initialValue;
  final TextInputType? keyboardType;
  final String? validator;

  final String formProperty;
  final Map<String, String> formValues;

  const CustonInputField({
    Key? key,
    this.hintText,
    this.labelText,
    this.helperText,
    this.icon,
    this.suffixIcon,
    this.minCharacters,
    this.maxCharacters,
    this.autofocus,
    this.isPassword,
    this.initialValue,
    this.keyboardType,
    this.validator,
    required this.formProperty,
    required this.formValues,
  }) : super(key: key);

  @override
  Widget build(BuildContext context) {
    dynamic validador = [
      {
        'type': 'email',
        'regex': RegExp(
            r'^[a-zA-Z0-9.!#$%&’*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\.[a-zA-Z0-9-]+)*$'),
        'message': 'Correo no válido'
      },
      {
        'type': 'password',
        'regex': RegExp(r'^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[a-zA-Z\d]{6,}$'),
        'message':
            'Contraseña no válida.\nDebe tener al menos 6 caracteres.\nUna mayúscula una minúscula y un número.'
      },
      {
        'type': 'number',
        'regex': RegExp(r'^[0-9]{8,}$'),
        'message': 'Número no válido',
      },
    ];

    return TextFormField(
      autofocus: autofocus ?? false,
      initialValue: initialValue,
      textCapitalization: TextCapitalization.words,
      onChanged: (value) {
        formValues[formProperty] = value;
      },
      validator: (value) {
        if (value == null || value.isEmpty) {
          return 'Este campo no puede estar vacio';
        }
        if (minCharacters != null && value.length < minCharacters!) {
          return 'Este campo debe tener al menos $minCharacters caracteres';
        }
        if (maxCharacters != null && value.length > maxCharacters!) {
          return 'Este campo no puede tener mas de $maxCharacters caracteres';
        }
        if (validator != null) {
          for (var i = 0; i < validador.length; i++) {
            if (validador[i]['type'] == validator) {
              if (!validador[i]['regex'].hasMatch(value)) {
                return validador[i]['message'];
              }
            }
          }
        }
        return null;
      },
      autovalidateMode: AutovalidateMode.onUserInteraction,
      decoration: InputDecoration(
        hintText: hintText,
        labelText: labelText,
        helperText: helperText,
        icon: icon != null ? Icon(icon) : null,
        suffixIcon: suffixIcon == null ? null : Icon(suffixIcon),
      ),
      obscureText: isPassword ?? false,
      keyboardType: keyboardType ?? TextInputType.text,
    );
  }
}
