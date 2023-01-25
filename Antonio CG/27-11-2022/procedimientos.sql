-- Ejecutar el procedimiento para cambiar el estado de la sesión a expirada cuando la fecha de expiración sea menor a la fecha actual si la sesión está activa
CALL change_status_expired_session();
-- calculate_total_order
CALL calculate_total_order(1);